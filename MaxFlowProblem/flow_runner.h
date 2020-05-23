#pragma once
#include "matrix.h"
#include "adj_list.h"
class flow_runner
{
public:
	static void run_flow_in_matrix_network(int begNode, int endNode, int flow, matrix<int>& network);
	static void run_flow_in_adjList_network(int begNode, int endNode, int flow, adj_list& network);
private:
	static void run_forward_flow_in_matrix_network(int begNode, int endNode, int flow, matrix<int>& network);
	static void run_forward_flow_in_adjList_network(int begNode, int endNode, int flow, adj_list& network);
	static void run_reverse_flow_in_matrix_network(int begNode, int endNode, int flow, matrix<int>& network);
	static void run_reverse_flow_in_adjList_network(int begNode, int endNode, int flow, adj_list& network);
};

