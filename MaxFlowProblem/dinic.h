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
	int* p;
	network_params networkParams;

	virtual int find_max_flow(int curVertex, int curFlow);
	virtual bool bfs();
	void run_flow(int begNode, int endNode, int flow);
	virtual void run_forward_flow(int begNode, int endNode, int flow);
	virtual void run_reverse_flow(int begNode, int endNode, int flow);
};

