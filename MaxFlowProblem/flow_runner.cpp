#include "flow_runner.h"

void flow_runner::run_flow_in_matrix_network(int begNode, int endNode, int flow, matrix<int>& network)
{
	run_forward_flow_in_matrix_network(begNode, endNode, flow, network);
	run_reverse_flow_in_matrix_network(begNode, endNode, flow, network);
}

void flow_runner::run_flow_in_adjList_network(int begNode, int endNode, int flow, adj_list& network)
{
	run_forward_flow_in_adjList_network(begNode, endNode, flow, network);
	run_reverse_flow_in_adjList_network(begNode, endNode, flow, network);
}

void flow_runner::run_forward_flow_in_matrix_network(int begNode, int endNode, int flow, matrix<int>& network)
{
	network[begNode][endNode] -= flow;
}

void flow_runner::run_forward_flow_in_adjList_network(int begNode, int endNode, int flow, adj_list& network)
{
	auto it = find_if(network[begNode].begin(), network[begNode].end(),
		[endNode](auto p) {return p.first == endNode; });
	network[begNode][distance(network[begNode].begin(), it)].second -= flow;
}

void flow_runner::run_reverse_flow_in_matrix_network(int begNode, int endNode, int flow, matrix<int>& network)
{
	network[endNode][begNode] += flow;
}

void flow_runner::run_reverse_flow_in_adjList_network(int begNode, int endNode, int flow, adj_list& network)
{
	auto it = find_if(network[endNode].begin(), network[endNode].end(),
		[begNode](auto p) {return p.first == begNode; });
	network[endNode][distance(network[endNode].begin(), it)].second += flow;
}
