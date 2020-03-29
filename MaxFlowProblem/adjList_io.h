#pragma once
#include "io.h"
#include "adjList_ff.h"

class adjList_io : public io
{
public:
	adjList_io(string inFileName, string outFileName);

	void read(graph& graph, int& v, int& e, int& source, int& dest);
};

