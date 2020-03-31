#pragma once
#include "matrix.h"
#include <vector>

class network_generator
{
public:
	network_generator(int v, int e, int source, int dest, int capacity = 100);
	matrix<int> generate();
private:
	matrix<int> graph;
	bool* visited;
	int v, e, source, dest, capacity;

	void buildBasis(int v);
	int buildEdge(int v);
};

