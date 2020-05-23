#pragma once
#include "dinic.h"
#include "matrix_network.h"

class matrix_dinic : public dinic
{
public:
	explicit matrix_dinic(matrix_network network);

	std::string get_name() override final;
private:
	matrix<int> network;

	int find_max_flow(int curNode, int curFlow) override;
	bool bfs() override;
};

