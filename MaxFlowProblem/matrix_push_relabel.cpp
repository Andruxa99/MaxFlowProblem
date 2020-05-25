#include "matrix_push_relabel.h"
#include "flow_runner.h"

matrix_push_relabel::matrix_push_relabel(matrix_network network)
	:push_relabel(network), network(network.get_network()) {}

std::string matrix_push_relabel::get_name()
{
	return push_relabel::get_name() + " (матрица смежности)";
}

void matrix_push_relabel::excesses_init()
{
	for (int i = 1; i <= networkParams.numOfNodes; i++)
		if (i != networkParams.source) {
			excesses[i] = network[networkParams.source][i];
			network[i][networkParams.source] += network[networkParams.source][i];
			network[networkParams.source][i] = 0;
		}
}

int matrix_push_relabel::find_neighbor_of_overflowing_node(int overflowingNode)
{
	int neighbor = 1;
	for (; neighbor <= networkParams.numOfNodes; neighbor++)
		if (network[overflowingNode][neighbor] > 0 && heights[overflowingNode] == heights[neighbor] + 1) break;
	return neighbor;
}

void matrix_push_relabel::push(int begNode, int endNode)
{
	int flow = std::min(excesses[begNode], network[begNode][endNode]);
	flow_runner::run_flow_in_matrix_network(begNode, endNode, flow, network);
	excesses[begNode] -= flow;
	excesses[endNode] += flow;
}

void matrix_push_relabel::lift(int curNode)
{
	int minHeight = 2 * networkParams.numOfNodes + 1;
	for (int i = 1; i <= networkParams.numOfNodes; i++)
		if (network[curNode][i] && heights[i] < minHeight)
			minHeight = heights[i];
	if (minHeight == 2 * networkParams.numOfNodes + 1) return;
	heights[curNode] = minHeight + 1;
}
