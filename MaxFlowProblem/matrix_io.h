#pragma once
#include "io.h"
#include "matrix_ff.h"

class matrix_io : public io
{
public:
	matrix_io(string inFileName, string outFileName);

	void read(matrix<int>& graph, int& v, int& e, int& source, int& dest);
};

