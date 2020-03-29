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
