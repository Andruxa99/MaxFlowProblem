#include "dinic.h"

dinic::dinic(network_base network)
	: networkParams(network.get_params())
{
	distances = new int[networkParams.numOfNodes + 1];
}

dinic::~dinic()
{
	delete[] distances;
}

int dinic::solve()
{
	startSearchTime = clock();
	int maxFlow = 0, curFlow;
	while (bfs()) {
		curFlow = find_max_flow(networkParams.source, INT_MAX);
		while (curFlow > 0) {
			maxFlow += curFlow;
			curFlow = find_max_flow(networkParams.source, INT_MAX);
		}
	}
	endSearchTime = clock();
	return maxFlow;
}

std::string dinic::get_name()
{
	name = "Алгоритм Диница";
	return IMaxFlowFinder::get_name();
}

bool dinic::bfs()
{
	std::fill(distances, distances + networkParams.numOfNodes + 1, INT_MAX);
	distances[networkParams.source] = 0;
	return false;
}
