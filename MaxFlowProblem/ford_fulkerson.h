#pragma once
#include "network_base.h"

class ford_fulkerson : public IMaxFlowFinder
{
public:
	explicit ford_fulkerson(network_base network);
	virtual ~ford_fulkerson();

	int solve() override;
	virtual std::string get_name() override;

protected:
	bool* visited;
	network_params networkParams;

	virtual int find_max_flow(int curVertex, int curFlow);
};

