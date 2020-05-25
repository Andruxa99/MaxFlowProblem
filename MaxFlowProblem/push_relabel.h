#pragma once
#include "network_base.h"

class push_relabel : public IMaxFlowFinder
{
public:
	explicit push_relabel(network_base network);
	virtual ~push_relabel();

	int solve() override;
	virtual std::string get_name() override;

protected:
	int* excesses;
	int* heights;
	network_params networkParams;

	virtual int find_max_flow() = 0;
	virtual void excesses_init() = 0;
	virtual void heights_init() = 0;
	virtual void push(int begNode, int endNode) = 0;
	virtual void lift(int curNode) = 0;
};

