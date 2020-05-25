#include "ford_fulkerson.h"
#include <algorithm>

ford_fulkerson::ford_fulkerson(network_base network)
    : networkParams(network.get_params())
{
    visited = new bool[networkParams.numOfNodes + 1]{};
}

ford_fulkerson::~ford_fulkerson()
{
    delete[] visited;
}

int ford_fulkerson::solve()
{
    startSearchTime = clock();
    int maxFlow = 0, curFlow;
    do {
        std::fill(visited + 1, visited + networkParams.numOfNodes + 1, false);
        curFlow = find_max_flow(networkParams.source, INT_MAX);
        maxFlow += curFlow;
    } while (curFlow > 0);

    endSearchTime = clock();
    return maxFlow;
}

std::string ford_fulkerson::get_name()
{
    name = "Алгоритм Форда-Фалкерсона";
    return IMaxFlowFinder::get_name();
}
