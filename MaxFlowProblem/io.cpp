#include "io.h"

io::io(string inFileName, string outFileName)
{
	in.open(inFileName, ios::app);
	out.open(outFileName);
}

io::~io()
{
	in.close();
	out.close();
}

void io::read(int& v, int& e, int& source, int& dest)
{
	in >> v >> e >> source >> dest;
}

void io::write(int value)
{
	out << value << endl;
}

void io::write(const matrix<int> &graph)
{
	for (size_t i = 0; i < graph.getXSize(); i++) {
		for (size_t j = 0; j < graph.getYSize(); j++)
			out << graph[i][j] << " ";
		out << endl;
	}

}
