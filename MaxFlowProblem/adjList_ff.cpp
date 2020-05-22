#include "adjList_ff.h"
#include <algorithm>

adjList_ff::adjList_ff(adjList_network network)
    : ford_fulkerson(network), network(network.get_network()) {}

std::string adjList_ff::get_name()
{
    return ford_fulkerson::get_name() + " (список смежности)";
}

int adjList_ff::find_max_flow(int curNode, int curFlow)
{
    if (curNode == networkParams.dest) return curFlow;
    visited[curNode] = true;
    for (auto nextNode : network[curNode]) {
        if (!visited[nextNode.first] && nextNode.second > 0) {
            int maxFlow = find_max_flow(nextNode.first, std::min(curFlow, nextNode.second));
            if (maxFlow > 0) {
                run_flow(curNode, nextNode.first, maxFlow);
                return maxFlow;
            }
        }
    }
    return 0;
}

void adjList_ff::run_forward_flow(int begNode, int endNode, int flow)
{
    auto it = find_if(network[begNode].begin(), network[begNode].end(), 
        [endNode](auto p){return p.first == endNode; });
    network[begNode][distance(network[begNode].begin(), it)].second -= flow;
}

void adjList_ff::run_reverse_flow(int begNode, int endNode, int flow)
{
    auto it = find_if(network[endNode].begin(), network[endNode].end(), 
        [begNode](auto p){return p.first == begNode; });
    network[endNode][distance(network[endNode].begin(), it)].second += flow;
}
