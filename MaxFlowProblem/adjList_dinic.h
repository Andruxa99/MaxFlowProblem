#pragma once
#include "dinic.h"
#include "adjList_network.h"

class adjList_dinic : public dinic
{
public:
	explicit adjList_dinic(adjList_network network);

	std::string get_name() override final;
private:
	adj_list network;

	int find_max_flow(int curNode, int curFlow) override;
	bool bfs() override;
};

