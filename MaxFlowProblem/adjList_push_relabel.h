#pragma once
#include "push_relabel.h"
#include "adjList_network.h"

class adjList_push_relabel : public push_relabel
{
public:
	explicit adjList_push_relabel(adjList_network network);

	std::string get_name() override final;

private:
	adj_list network;

	void excesses_init() override;
	int find_neighbor_of_overflowing_node(int overflowingNode) override;
	void push(int begNode, int endNode) override;
	void lift(int curNode) override;
};

