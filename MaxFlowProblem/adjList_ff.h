#pragma once
#include "ford_fulkerson.h"
#include "adjList_network.h"

class adjList_ff : public ford_fulkerson
{
public:
	explicit adjList_ff(adjList_network network);

	std::string get_name() override final;
private:
	adj_list network;

	int find_max_flow(int curNode, int curFlow) override;
	void run_forward_flow(int begNode, int endNode, int flow) override;
	void run_reverse_flow(int begNode, int endNode, int flow) override;
};

