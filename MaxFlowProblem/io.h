#pragma once
#include <string>
#include <fstream>
using namespace std;

class io
{
public:
	io(string inFileName, string outFileName);
	~io();

protected:
	ifstream in;
	ofstream out;

	void read(int& v, int& e, int& source, int& dest);

public:
	void write(int value);
};

