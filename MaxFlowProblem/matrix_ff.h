#pragma once
#include "ford_fulkerson.h"
#include "matrix_network.h"

class matrix_ff : public ford_fulkerson
{
public:
	explicit matrix_ff(matrix_network network);

	std::string get_name() override final;
private:
	matrix<int> network;

	int find_max_flow(int curNode, int curFlow) override;
	void run_forward_flow(int begNode, int endNode, int flow) override;
	void run_reverse_flow(int begNode, int endNode, int flow) override;
};

