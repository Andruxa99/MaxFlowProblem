#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "network_params.h"

typedef std::vector<std::tuple<int, int, int>> edges_list;
class network_io
{
public:
	network_io(std::string inFileName, std::string outFileName);
	~network_io();

	network_params read_network_params();
	void write_network(const edges_list& network, const network_params& params);

protected:
	std::ifstream in;
	std::ofstream out;
};

