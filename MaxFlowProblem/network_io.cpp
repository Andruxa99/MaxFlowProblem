#include "network_io.h"
#include <tuple>

network_io::network_io(std::string inFileName, std::string outFileName)
{
	in.open(inFileName);
	out.open(outFileName);
}

network_io::~network_io()
{
	in.close();
	out.close();
}

network_params network_io::read_network_params()
{
	int numOfNodes, numOfEdges, source, dest, maxWeight;
	in >> numOfNodes >> numOfEdges >> source >> dest >> maxWeight;
	return network_params{ numOfNodes, numOfEdges, source, dest, maxWeight };
}

void network_io::write_network(const edges_list& network, const network_params& params)
{
	out << params.numOfNodes << ' ' << params.numOfEdges << ' ' << params.source
		<< ' ' << params.dest << ' ' << params.maxWeight << '\n';
	for (auto edge : network)
		out << std::get<0>(edge) << ' ' << std::get<1>(edge) << ' ' << std::get<2>(edge) << '\n';
}
