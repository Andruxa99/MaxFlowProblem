#include "network_converter.h"
#include <tuple>
#include <iostream>

matrix<int> network_converter::to_adj_matrix(const edges_list& network, network_params params)
{
	matrix<int> matrixNetwork(params.numOfNodes + 1, params.numOfNodes + 1);
	for (size_t i = 0; i < network.size(); i++) {
		int begNode, endNode, weigth;
		std::tie(begNode, endNode, weigth) = network[i];
		matrixNetwork[begNode][endNode] = weigth;
	}
	return matrixNetwork;
}

adj_list network_converter::to_adj_list(const edges_list& network, network_params params)
{
	adj_list adjListNetwork(params.numOfNodes + 1);
	for (size_t i = 0; i < network.size(); i++) {
		int begNode, endNode, weigth;
		std::tie(begNode, endNode, weigth) = network[i];
		adjListNetwork.add_edge(begNode, endNode, weigth);
		adjListNetwork.add_edge(endNode, begNode, 0);
	}
	return adjListNetwork;
}
