#include "matrix_io.h"

matrix_io::matrix_io(string inFileName, string outFileName)
	: io(inFileName, outFileName) {}

void matrix_io::read(matrix<int>& graph, int& v, int& e, int& source, int& dest)
{
	io::read(v, e, source, dest);
	graph = matrix<int>(v + 1, v + 1);
	for (int i = 0, v1, v2, cap; i < e; i++) {
		in >> v1 >> v2 >> cap;
		graph[v1][v2] = cap;
	}

}
