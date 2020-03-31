#pragma once
#include "matrix.h"
#include <string>
#include <fstream>
using namespace std;

class io
{
public:
	io(string inFileName, string outFileName);
	~io();

	void write(int value);
	void write(const matrix<int> &graph);
	void read(int& v, int& e, int& source, int& dest);

protected:
	ifstream in;
	ofstream out;
};

