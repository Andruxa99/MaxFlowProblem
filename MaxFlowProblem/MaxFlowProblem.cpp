#include <iostream>
#include <clocale>
#include <vector>
#include <tuple>
#include <ctime>
#include "IMaxFlowFinder.h"
#include "network_params.h"
#include "network_generator.h"
#include "network_converter.h"
#include "network_io.h"
#include "matrix_network.h"
#include "adjList_network.h"
#include "matrix_ff.h"
#include "adjList_ff.h"


network_params read_network_params(network_io& ioStream);
std::vector<network_base*> create_networks(const edges_list& network, const network_params& networkParams);
matrix_network* create_matrix_network(const edges_list& network, const network_params& networkParams);
adjList_network* create_adjList_network(const edges_list& network, const network_params& networkParams);
edges_list generate_network(const network_params& networkParams);
std::vector<IMaxFlowFinder*> create_finders(std::vector<network_base*> networks);
std::vector<ford_fulkerson*> create_ford_fulkerson_finders(std::vector<network_base*> networks);
void run_algorithms(std::vector<IMaxFlowFinder*> finders);

clock_t begTime, endTime, runTime;

int main()
{
    setlocale(LC_CTYPE, "rus");
    network_io ioStream("params.txt", "network.txt");
    auto networkParams = read_network_params(ioStream);
    std::cout << "Генерация сети...";
    auto network = generate_network(networkParams);
    std::cout << "\tok\t" << endTime - begTime << " мс." << '\n';

    std::cout << "Преобразования сети...";
    auto allDiffNetworks = create_networks(network, networkParams);
    std::cout << "\tok\t" << endTime - begTime << " мс." << '\n';

    auto finders = create_finders(allDiffNetworks);

    std::cout << "Исполнение алгоритмов...";
    run_algorithms(finders);

    std::cout << "Печать данных сети...";
    begTime = clock();
    ioStream.write_network(network, networkParams);
    endTime = clock();
    std::cout << "\tok\t" << endTime - begTime << " мс." << '\n';

    std::cout << "Программа успешно выполнена!" << '\n';
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
    networks.push_back(create_matrix_network(network, networkParams));
    networks.push_back(create_adjList_network(network, networkParams));
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
    auto ff_finders = create_ford_fulkerson_finders(networks);
    for (auto finder : ff_finders)
        finders.push_back(finder);
    return finders;
}

std::vector<ford_fulkerson*> create_ford_fulkerson_finders(std::vector<network_base*> networks)
{
    std::vector<ford_fulkerson*> ff_finders;
    matrix_network *m_network = dynamic_cast<matrix_network*>(networks[0]);
    if (m_network != nullptr)
        ff_finders.push_back(new matrix_ff(*m_network));
    adjList_network *l_network = dynamic_cast<adjList_network*>(networks[1]);
    if (l_network != nullptr)
        ff_finders.push_back(new adjList_ff(*l_network));
    return ff_finders;
}

void run_algorithms(std::vector<IMaxFlowFinder*> finders)
{
    for (size_t i = 0; i < finders.size(); i++) {
        int result = finders[i]->solve();
        std::cout << '\n' << finders[i]->get_name() << std::endl
            << "\t" << "Максимальный поток: " << result << std::endl
            << "\t" << "Время выполнения алгоритма: " << finders[i]->get_running_time() << " мс." << '\n';
    }
}
