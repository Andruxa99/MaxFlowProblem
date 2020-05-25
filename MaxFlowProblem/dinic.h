#pragma once
#include "network_base.h"

class dinic : public IMaxFlowFinder
{
public:
	explicit dinic(network_base network);
	virtual ~dinic();

	int solve() override;
	virtual std::string get_name() override;

protected:
	int* distances;
	network_params networkParams;

	virtual int find_max_flow(int curVertex, int curFlow) = 0;
	virtual bool bfs();
};

