#include "network_generator.h"
#include <iostream>

network_generator::network_generator(int v, int e, int source, int dest, int capacity)
	: v(v), e(e), source(source), dest(dest), capacity(capacity) 
{
	graph = matrix<int>(v + 1, v + 1);
}


matrix<int> network_generator::generate()
{
	buildBasis(source);
	while (e - v + 1 > 0)
	{
		int v1, v2;
		while (true)
		{
			v1 = rand() % v + 1;
			if (v1 == dest) continue;
			v2 = buildEdge(v1);
			if (v2 != -1 && v2 != source) break;
		}
		graph[v1][v2] = rand() % capacity + 1;
		e--;
	}

	return graph;
}

void network_generator::buildBasis(int v)
{
	while (v != dest)
		graph[v++][v] = rand() % capacity + 1;
}

int network_generator::buildEdge(int v)
{
	std::vector<int> right;
	for (size_t i = 1; i < graph[v].getSize(); i++)
		if (v != i && graph[v][i] == 0)
			right.push_back(i);
	return right.size() != 0 
		? right[rand() % right.size()]
		: -1;
}
