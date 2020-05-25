#pragma once
#include "push_relabel.h"
#include "matrix_network.h"

class matrix_push_relabel : public push_relabel
{
public:
	explicit matrix_push_relabel(matrix_network network);

	std::string get_name() override final;

private:
	matrix<int> network;

	void excesses_init() override;
	int find_neighbor_of_overflowing_node(int overflowingNode) override;
	void push(int begNode, int endNode) override;
	void lift(int curNode) override;
};

