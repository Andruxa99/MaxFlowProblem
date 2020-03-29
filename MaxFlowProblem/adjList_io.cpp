#include "adjList_io.h"

adjList_io::adjList_io(string inFileName, string outFileName)
	: io(inFileName, outFileName) {}

void adjList_io::read(graph& graph, int& v, int& e, int& source, int& dest)
{
	io::read(v, e, source, dest);
	graph.resize(v + 1);
	for (int i = 0, v1, v2, cap; i < e; i++) {
		in >> v1 >> v2 >> cap;
		graph[v1].push_back(make_pair(v2, cap));
		graph[v2].push_back(make_pair(v1, 0));
	}
}
