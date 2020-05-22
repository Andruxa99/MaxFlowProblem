#include "adj_list.h"

adj_list::adj_list(int numOfNodes)
{
	network.resize(numOfNodes);
}

void adj_list::add_edge(int begNode, int endNode, int weight)
{
	network[begNode].push_back(std::make_pair(endNode, weight));
}

size_t adj_list::get_size() const
{
	return network.size();
}

std::vector<std::pair<int, int>>& adj_list::operator[](int node)
{
	return network[node];
}
