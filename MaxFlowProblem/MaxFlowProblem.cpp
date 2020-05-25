#include <iostream>
#include <clocale>
#include <vector>
#include <tuple>
#include <ctime>
#include <string>
#include <stdarg.h>
#include "IMaxFlowFinder.h"
#include "network_params.h"
#include "network_generator.h"
#include "network_converter.h"
#include "network_io.h"
#include "matrix_network.h"
#include "adjList_network.h"
#include "matrix_ff.h"
#include "adjList_ff.h"
#include "matrix_dinic.h"
#include "adjList_dinic.h"
#include "matrix_push_relabel.h"

network_params read_network_params(network_io& ioStream);
std::vector<network_base*> create_networks(const edges_list& network, const network_params& networkParams);
matrix_network* create_matrix_network(const edges_list& network, const network_params& networkParams);
adjList_network* create_adjList_network(const edges_list& network, const network_params& networkParams);
edges_list generate_network(const network_params& networkParams);
std::vector<IMaxFlowFinder*> create_finders(std::vector<network_base*> networks);
std::vector<IMaxFlowFinder*> create_ford_fulkerson_finders(std::vector<network_base*> networks);
std::vector<IMaxFlowFinder*> create_dinic_finders(std::vector<network_base*> networks);
std::vector<IMaxFlowFinder*> create_push_relabel_finders(std::vector<network_base*> networks);
void add_finders(std::vector<IMaxFlowFinder*>& oldFinders, std::vector<IMaxFlowFinder*> newFinders);
void run_algorithms(std::vector<IMaxFlowFinder*> finders);
void print_message(std::string pattern, ...);

clock_t begTime, endTime, runTime;

int main()
{
    setlocale(LC_CTYPE, "rus");

    print_message("sss", "Выберите способ задания сети:\n",
        "[1] - Автоматическая генерация\n", "[2] - Чтение данных из файла\n");
    int inputChoice;
    std::cin >> inputChoice;
    network_params networkParams;
    edges_list network;
    if (inputChoice == 1) {
        network_io ioStream("params.txt", "network.txt");

        print_message("s", "Чтение параметров сети...");
        networkParams = read_network_params(ioStream);
        print_message("sis", "\tok\t", endTime - begTime, " мс.\n");

        print_message("s", "Генерация сети...");
        network = generate_network(networkParams);
        print_message("sis", "\tok\t", endTime - begTime, " мс.\n");

        print_message("s", "\nПечать данных сети...");
        begTime = clock();
        ioStream.write_network(network, networkParams);
        endTime = clock();
        print_message("sis", "\tok\t", endTime - begTime, " мс.\n");
    }
    else if (inputChoice == 2) {
        network_io ioStream("network.txt");
        print_message("s", "Чтение данных сети из файла...");
        begTime = clock();
        std::tie(networkParams, network) = ioStream.read_network();
        endTime = clock();
        print_message("sis", "\tok\t", endTime - begTime, " мс.\n");
    }

    print_message("s", "Преобразования сети...");
    auto allDiffNetworks = create_networks(network, networkParams);
    print_message("sis", "\tok\t", endTime - begTime, " мс.\n");

    print_message("s", "Создание алгоритмов...");
    auto finders = create_finders(allDiffNetworks);
    print_message("sis", "\tok\t", endTime - begTime, " мс.\n");

    print_message("s", "Исполнение алгоритмов...");
    run_algorithms(finders);

    print_message("ss", "\nПрограмма успешно выполнена!\n", "\a");
    for (auto network : allDiffNetworks)
        delete network;

    for (auto finder : finders)
        delete finder;
    return 0;
}

network_params read_network_params(network_io& ioStream)
{
    return ioStream.read_network_params();
}

std::vector<network_base*> create_networks(const edges_list& network, const network_params& networkParams)
{
    std::vector<network_base*> networks;
    begTime = clock();
    networks.emplace_back(create_matrix_network(network, networkParams));
    networks.emplace_back(create_adjList_network(network, networkParams));
    endTime = clock();
    return networks;
}

matrix_network* create_matrix_network(const edges_list& network, const network_params& networkParams)
{
    return new matrix_network(networkParams, network_converter::to_adj_matrix(network, networkParams));
}

adjList_network* create_adjList_network(const edges_list& network, const network_params& networkParams)
{
    return new adjList_network(networkParams, network_converter::to_adj_list(network, networkParams));
}

edges_list generate_network(const network_params& networkParams) {
    network_generator generator(networkParams);
    begTime = clock();
    auto network = generator.generate_network();
    endTime = clock();
    return network;
}

std::vector<IMaxFlowFinder*> create_finders(std::vector<network_base*> networks)
{
    std::vector<IMaxFlowFinder*> finders;
    begTime = clock();
    auto ff_finders = create_ford_fulkerson_finders(networks);
    add_finders(finders, ff_finders);
    auto dinic_finders = create_dinic_finders(networks);
    add_finders(finders, dinic_finders);
    auto push_relabel_finders = create_push_relabel_finders(networks);
    add_finders(finders, push_relabel_finders);
    endTime = clock();
    return finders;
}

std::vector<IMaxFlowFinder*> create_ford_fulkerson_finders(std::vector<network_base*> networks)
{
    std::vector<IMaxFlowFinder*> ff_finders;
    matrix_network *m_network = dynamic_cast<matrix_network*>(networks[0]);
    if (m_network != nullptr)
        ff_finders.emplace_back(new matrix_ff(*m_network));
    adjList_network *l_network = dynamic_cast<adjList_network*>(networks[1]);
    if (l_network != nullptr)
        ff_finders.emplace_back(new adjList_ff(*l_network));
    return ff_finders;
}

std::vector<IMaxFlowFinder*> create_dinic_finders(std::vector<network_base*> networks)
{
    std::vector<IMaxFlowFinder*> dinic_finders;
    matrix_network* m_network = dynamic_cast<matrix_network*>(networks[0]);
    if (m_network != nullptr)
        dinic_finders.emplace_back(new matrix_dinic(*m_network));
    adjList_network* l_network = dynamic_cast<adjList_network*>(networks[1]);
    if (l_network != nullptr)
        dinic_finders.emplace_back(new adjList_dinic(*l_network));
    return dinic_finders;
}

std::vector<IMaxFlowFinder*> create_push_relabel_finders(std::vector<network_base*> networks)
{
    std::vector<IMaxFlowFinder*> push_relabel_finders;
    matrix_network* m_network = dynamic_cast<matrix_network*>(networks[0]);
    if (m_network != nullptr)
        push_relabel_finders.emplace_back(new matrix_push_relabel(*m_network));
    return push_relabel_finders;
}

void add_finders(std::vector<IMaxFlowFinder*>& oldFinders, std::vector<IMaxFlowFinder*> newFinders) {
    for (auto finder : newFinders)
        oldFinders.emplace_back(finder);
}

void run_algorithms(std::vector<IMaxFlowFinder*> finders)
{
    for (auto finder : finders) {
        int result = finder->solve();
        std::cout << '\n' << finder->get_name() << std::endl
            << "\t" << "Максимальный поток: " << result << std::endl
            << "\t" << "Время выполнения алгоритма: " << finder->get_running_time() << " мс." << '\n';
    }
}

void print_message(std::string pattern, ...)
{
    va_list args;
    va_start(args, pattern);
    for (auto format : pattern)
        if (format == 'i')
            std::cout << va_arg(args, int);
        else if (format == 's')
            std::cout << va_arg(args, const char*);
    va_end(args);
}
