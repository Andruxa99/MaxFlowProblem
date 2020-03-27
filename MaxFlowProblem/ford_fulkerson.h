#pragma once
#include <vector>
#include "matrix.cpp"

typedef vector<vector<pair<int, int>>> graph;
const int INF = (int)1e9;
const int MAX_V = (int)1e3;

class ford_fulkerson
{
public:
	ford_fulkerson(int v, int e, int source, int dest);
	virtual ~ford_fulkerson();

protected:
	bool* visited;
	int numOfVertex, numOfEdges, source, dest;

	virtual int find_flow(int v, int flow) = 0;
public:
	int solve();
};

