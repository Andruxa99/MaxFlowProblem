#include "matrix_dinic.h"
#include "flow_runner.h"
#include <queue>

matrix_dinic::matrix_dinic(matrix_network network)
	: dinic(network), network(network.get_network()) {}

std::string matrix_dinic::get_name()
{
	return dinic::get_name() + " (матрица смежности)";
}

int matrix_dinic::find_max_flow(int curNode, int curFlow)
{
	if (curNode == networkParams.dest || curFlow == 0)
		return curFlow;
	for (int i = 1; i <= networkParams.numOfNodes; i++) {
		if (distances[i] == distances[curNode] + 1) {
			int maxFlow = find_max_flow(i, std::min(curFlow, network[curNode][i]));
			if (maxFlow > 0) {
				flow_runner::run_flow_in_matrix_network(curNode, i, maxFlow, network);
				return maxFlow;
			}
		}
	}
	return 0;
}

bool matrix_dinic::bfs()
{
	dinic::bfs();
	std::queue<int> q;
	q.push(networkParams.source);

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (int i = 1; i <= networkParams.numOfNodes; i++) 
			if (network[curNode][i] && distances[i] == INT_MAX) {
				distances[i] = distances[curNode] + 1;
				q.push(i);
			}
	}
	return distances[networkParams.dest] != INT_MAX;
}
