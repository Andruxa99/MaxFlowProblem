#include "matrix_ff.h"

matrix_ff::matrix_ff(const matrix<int>& g, int v, int e, int source, int dest)
    : ford_fulkerson(v, e, source, dest), graph(matrix<int>(g)) {}

int matrix_ff::find_flow(int v, int flow)
{
    if (v == dest) return flow;
    visited[v] = true;
    for (int i = 1; i <= numOfVertex; i++) {
        if (!visited[i] && graph[v][i] > 0) {
            int maxResult = find_flow(i, std::min(flow, graph[v][i]));
            if (maxResult > 0) {
                graph[v][i] -= maxResult;
                graph[i][v] += maxResult;
                return maxResult;
            }
        }
    }
    return 0;
}
