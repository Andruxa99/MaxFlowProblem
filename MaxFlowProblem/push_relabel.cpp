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

int push_relabel::find_max_flow()
{
	while (true) {
		int overflowingNode = find_overflowing_node();
		if (overflowingNode == networkParams.numOfNodes + 1) break;

		int neighbor = find_neighbor_of_overflowing_node(overflowingNode);
		if (neighbor <= networkParams.numOfNodes)
			push(overflowingNode, neighbor);
		else
			lift(overflowingNode);
	}

	return excesses[networkParams.dest];
}

void push_relabel::heights_init()
{
	heights[networkParams.source] = networkParams.numOfNodes;
}

int push_relabel::find_overflowing_node()
{
	int overflowingNode = 1;
	for (; overflowingNode <= networkParams.numOfNodes; overflowingNode++)
		if (overflowingNode != networkParams.source && overflowingNode != networkParams.dest && excesses[overflowingNode] > 0) break;
	return overflowingNode;
}
