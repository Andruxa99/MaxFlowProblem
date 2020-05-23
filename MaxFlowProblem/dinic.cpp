#include "dinic.h"

dinic::dinic(network_base network)
	: networkParams(network.get_params())
{
	distances = new int[networkParams.numOfNodes + 1];
	p = new int[networkParams.numOfNodes + 1];
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
		std::fill(p, p + networkParams.numOfNodes + 1, 0);
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

int dinic::find_max_flow(int curVertex, int curFlow)
{
	return 0;
}

bool dinic::bfs()
{
	std::fill(distances, distances + networkParams.numOfNodes + 1, INT_MAX);
	distances[networkParams.source] = 0;
	return false;
}

void dinic::run_flow(int begNode, int endNode, int flow)
{
	run_forward_flow(begNode, endNode, flow);
	run_reverse_flow(begNode, endNode, flow);
}

void dinic::run_forward_flow(int begNode, int endNode, int flow) {}

void dinic::run_reverse_flow(int begNode, int endNode, int flow) {}
