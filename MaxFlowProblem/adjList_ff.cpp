#include "adjList_ff.h"
#include <algorithm>

adjList_ff::adjList_ff(graph g, int v, int e, int source, int dest)
    : ford_fulkerson(v, e, source, dest), g(graph(g)) {}

int adjList_ff::find_flow(int v, int flow)
{
    if (v == dest) return flow;
    visited[v] = true;
    for (auto next : g[v]) {
        if (!visited[next.first] && next.second > 0) {
            int maxResult = find_flow(next.first, min(flow, next.second));
            if (maxResult > 0) {
                auto it = find_if(g[v].begin(), g[v].end(), [next](pair<int, int> p) -> bool {return p.first == next.first; });
                g[v][distance(g[v].begin(), it)].second -= maxResult;

                it = find_if(g[next.first].begin(), g[next.first].end(), [v](pair<int, int> p) -> bool {return p.first == v; });
                g[next.first][distance(g[next.first].begin(), it)].second += maxResult;
                return maxResult;
            }
        }
    }
    return 0;
}
