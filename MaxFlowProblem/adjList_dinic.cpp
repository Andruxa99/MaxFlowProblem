#include "adjList_dinic.h"
#include <algorithm>
#include <queue>

adjList_dinic::adjList_dinic(adjList_network network)
	:dinic(network), network(network.get_network()) {}

std::string adjList_dinic::get_name()
{
	return dinic::get_name() + " (список смежности)";
}

int adjList_dinic::find_max_flow(int curNode, int curFlow)
{
	if (curNode == networkParams.dest || curFlow == 0)
		return curFlow;
	for (auto nextNode : network[curNode]){
		if (nextNode.second > 0) {
			if (distances[nextNode.first] == distances[curNode] + 1) {
				int maxFlow = 0;
				maxFlow = find_max_flow(nextNode.first, std::min(curFlow, nextNode.second));
				if (maxFlow > 0) {
					run_flow(curNode, nextNode.first, maxFlow);
					return maxFlow;
				}
			}
		}
	}
	return 0;
}

bool adjList_dinic::bfs()
{
	dinic::bfs();
	std::queue<int> q;
	q.push(networkParams.source);

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (auto nextNode : network[curNode])
			if (nextNode.second > 0 && distances[nextNode.first] == INT_MAX) {
				distances[nextNode.first] = distances[curNode] + 1;
				q.push(nextNode.first);
		}
	}
	return distances[networkParams.dest] != INT_MAX;
}

void adjList_dinic::run_forward_flow(int begNode, int endNode, int flow)
{
	auto it = find_if(network[begNode].begin(), network[begNode].end(),
		[endNode](auto p) {return p.first == endNode; });
	network[begNode][distance(network[begNode].begin(), it)].second -= flow;
}

void adjList_dinic::run_reverse_flow(int begNode, int endNode, int flow)
{
	auto it = find_if(network[endNode].begin(), network[endNode].end(),
		[begNode](auto p) {return p.first == begNode; });
	network[endNode][distance(network[endNode].begin(), it)].second += flow;
}
