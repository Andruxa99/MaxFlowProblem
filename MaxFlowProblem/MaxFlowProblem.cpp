#include <iostream>
#include <ctime>
#include <clocale>
#include "matrix_ff.h"
//#include "adjList_ff.h"
#include "matrix_io.h"
//#include "adjList_io.h"
#include "network_generator.h"

int main()
{
    setlocale(LC_CTYPE, "rus");
    matrix<int> graph;
    int v, e, source, dest;

    cout << "Считывание входных данных из файла..." << endl;
    io io("paramsInput.txt", "networkInput.txt");
    io.read(v, e, source, dest);

    cout << "Генерация сети..." << endl;
    network_generator generator(v, e, source, dest);
    graph = generator.generate();

    io.write(v), io.write(e), io.write(source), io.write(dest);
    io.write(graph);

    matrix_io matrix_io("networkInput.txt", "output.txt");
    matrix_io.read(graph, v, e, source, dest);

    matrix_ff matrix_ff(graph, v, e, source, dest);
    cout << "Выполнение алгоритма..." << endl;
    auto start = clock();
    int result = matrix_ff.solve();
    auto finish = clock();

    matrix_io.write(result);
    cout << "Время выполнения: " << (finish - start);
       
    return 0;
}
