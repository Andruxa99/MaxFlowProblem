#include "adjList_dinic.h"
#include <algorithm>
#include <queue>

adjList_dinic::adjList_dinic(adjList_network network)
	:dinic(network), network(network.get_network()) {}

std::string adjList_dinic::get_name()
{
	return dinic::get_name() + "(������ ���������)";
}

int adjList_dinic::find_max_flow(int curNode, int curFlow)
{
	if (curNode == networkParams.dest || curFlow == 0)
		return curFlow;
	for (int i = p[curNode]; i <= networkParams.numOfNodes; i++) {
		if (distances[i] == distances[curNode] + 1) {
			auto index = std::distance(network[curNode].begin(), std::find_if(network[curNode].begin(), network[curNode].end(),
				[i](auto edge) {return edge.first == i && edge.second; }));
			int maxFlow = 0;
			if (index < network[curNode].size()) 
				maxFlow = find_max_flow(i, std::min(curFlow, network[curNode][index].second));
			if (maxFlow > 0) {
				run_flow(curNode, i, maxFlow);
				return maxFlow;
			}
		}
		p[curNode]++;
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
		for (int i = 1; i <= networkParams.numOfNodes; i++) {
			auto index = std::distance(network[curNode].begin(), std::find_if(network[curNode].begin(), network[curNode].end(),
				[i](auto edge) {return edge.first == i; }));
			if (index < network[curNode].size() && network[curNode][index].second && distances[i] == INT_MAX) {
				distances[i] = distances[curNode] + 1;
				q.push(i);
			}
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
