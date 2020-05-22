#pragma once
#include <vector>

typedef std::vector<std::vector<std::pair<int, int>>> adjList;
class adj_list
{
public:
	explicit adj_list(int numOfNodes = 0);
	void add_edge(int begNode, int endNode, int weight);
	size_t get_size() const;

	std::vector<std::pair<int, int>>& operator[](int node);
private:
	adjList network;
};

