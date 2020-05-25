#include "adjList_push_relabel.h"
#include "flow_runner.h"

adjList_push_relabel::adjList_push_relabel(adjList_network network)
	:push_relabel(network), network(network.get_network()) {}

std::string adjList_push_relabel::get_name()
{
	return push_relabel::get_name() + " (список смежности)";
}

void adjList_push_relabel::excesses_init()
{
	for (auto edge : network[networkParams.source]) {
		if (edge.second > 0)
			excesses[edge.first] = edge.second;
		int sourceIndex = std::distance(network[edge.first].begin(), std::find_if(network[edge.first].begin(), network[edge.first].end(),
			[this](auto edge) {return edge.first == this->networkParams.source; }));
		network[edge.first][sourceIndex].second += edge.second;
		edge.second = 0;
	}
}

int adjList_push_relabel::find_neighbor_of_overflowing_node(int overflowingNode)
{
	int neighbor = networkParams.numOfNodes + 1;
	for (auto edge : network[overflowingNode])
		if (edge.second > 0 && heights[overflowingNode] == heights[edge.first] + 1) {
			neighbor = edge.first;
			break;
		}

	return neighbor;
}

void adjList_push_relabel::push(int begNode, int endNode)
{
	int endNodeIndex = std::distance(network[begNode].begin(), std::find_if(network[begNode].begin(), network[begNode].end(),
		[endNode](auto edge) {return edge.first == endNode; }));
	int flow = std::min(excesses[begNode], network[begNode][endNodeIndex].second);
	flow_runner::run_flow_in_adjList_network(begNode, endNode, flow, network);
	excesses[begNode] -= flow;
	excesses[endNode] += flow;
}

void adjList_push_relabel::lift(int curNode)
{
	int minHeight = 2 * networkParams.numOfNodes + 1;
	for (auto edge : network[curNode])
		if (edge.second > 0 && heights[edge.first] < minHeight)
			minHeight = heights[edge.first];
	if (minHeight == 2 * networkParams.numOfNodes + 1) return;
	heights[curNode] = minHeight + 1;
}
