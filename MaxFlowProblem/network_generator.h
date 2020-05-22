#pragma once
#include <vector>
#include "network_params.h"

typedef std::vector<std::tuple<int, int, int>> edges_list;
class network_generator
{
public:
	explicit network_generator(network_params params);
	edges_list generate_network();

private:
	network_params params;
	void build_basis(edges_list &network);
	int select_begin_node();
	int select_end_node(int begNode, const edges_list& network);
	std::vector<int> select_available_nodes(int begNode, const edges_list& network);
	void build_edge(int begNode, int endNode, edges_list& network);
};

