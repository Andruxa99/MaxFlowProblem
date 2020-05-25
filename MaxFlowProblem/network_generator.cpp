#include "network_generator.h"
#include <ctime>
#include <set>
#include <tuple>
#include <algorithm>

network_generator::network_generator(network_params params)
	: params(params) {}

edges_list network_generator::generate_network()
{
	srand(static_cast<unsigned>(time(NULL)));
	edges_list network;
	build_basis(network);
	int numOfBaseEdges = params.numOfNodes - 1;
	int edgeCounter = params.numOfEdges - numOfBaseEdges;
	while (edgeCounter > 0)
	{
		int begVertex, endVertex;
		while (true)
		{
			begVertex = select_begin_node();
			if (begVertex == params.dest) continue;
			endVertex = select_end_node(begVertex, network);
			if (endVertex != -1 && endVertex != params.source) break;
		}
		build_edge(begVertex, endVertex, network);
		edgeCounter--;
	}
	return network;
}

void network_generator::build_basis(edges_list& network)
{
	int curVertex = params.source;
	while (curVertex != params.numOfNodes)
		build_edge(curVertex++, curVertex, network);
}

void network_generator::build_edge(int begNode, int endNode, edges_list& network) 
{
	network.push_back({ begNode, endNode, rand() % params.maxWeight + 1 });
}

int network_generator::select_begin_node()
{
	return rand() % params.numOfNodes + 1;
}

int network_generator::select_end_node(int begNode, const edges_list& network)
{
	auto availableNodes = select_available_nodes(begNode, network);
	int numOfAvailableNodes = availableNodes.size();
	return numOfAvailableNodes != 0
		? availableNodes[rand() % numOfAvailableNodes]
		: -1;
}

std::vector<int> network_generator::select_available_nodes(int begNode, const edges_list& network)
{
	std::set<int> badNodes{ begNode };
	for (auto i : network) {
		if (std::get<0>(i) == begNode)
			badNodes.insert(std::get<1>(i));
		if (std::get<1>(i) == begNode)
			badNodes.insert(std::get<0>(i));
	}
	std::vector<int> availableNodes;
	for (int i = 1; i <= params.numOfNodes; i++)
		if (i != params.source && badNodes.find(i) == badNodes.end())
			availableNodes.push_back(i);
	return availableNodes;
}
