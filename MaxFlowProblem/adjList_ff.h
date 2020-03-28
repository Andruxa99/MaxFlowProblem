#pragma once
#include "ford_fulkerson.h"
class adjList_ff : public ford_fulkerson
{
public:
	adjList_ff(graph g, int v, int e, int source, int dest);
private:
	graph g;

	int find_flow(int v, int flow);
};

