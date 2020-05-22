#pragma once
#include "matrix.h"
#include "adj_list.h"
#include "network_params.h"

typedef std::vector<std::tuple<int, int, int>> edges_list;
class network_converter
{
public:
	static matrix<int> to_adj_matrix(const edges_list& network, network_params params);
	static adj_list to_adj_list(const edges_list& network, network_params params);
};

