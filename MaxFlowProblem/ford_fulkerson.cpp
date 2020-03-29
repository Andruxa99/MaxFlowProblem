#include "ford_fulkerson.h"
#include <algorithm>
using namespace std;

ford_fulkerson::ford_fulkerson(int v, int e, int source, int dest)
    : numOfVertex(v), numOfEdges(e), source(source), dest(dest)
{
    visited = new bool[MAX_V];
}

ford_fulkerson::~ford_fulkerson()
{
    delete[] visited;
}

int ford_fulkerson::solve()
{
    int maxFlow = 0, curFlow;
    do {
        fill(visited + 1, visited + numOfVertex + 1, false);
        curFlow = find_flow(source, INF);
        maxFlow += curFlow;
    } while (curFlow > 0);

    return maxFlow;
}
