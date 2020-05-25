#include "push_relabel.h"

push_relabel::push_relabel(network_base network)
	: networkParams(network.get_params())
{
	excesses = new int[networkParams.numOfNodes + 1]{};
	heights = new int[networkParams.numOfNodes + 1]{};
}

push_relabel::~push_relabel()
{
	delete[] excesses;
	delete[] heights;
}

int push_relabel::solve()
{
	startSearchTime = clock();
	excesses_init();
	heights_init();
	int maxFlow = find_max_flow();
	endSearchTime = clock();
	return maxFlow;
}

std::string push_relabel::get_name()
{
	name = "Алгоритм проталкивания предпотока";
	return IMaxFlowFinder::get_name();
}
