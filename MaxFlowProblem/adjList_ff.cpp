#include "adjList_ff.h"
#include "flow_runner.h"
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
                flow_runner::run_flow_in_adjList_network(curNode, nextNode.first, maxFlow, network);
                return maxFlow;
            }
        }
    }
    return 0;
}
