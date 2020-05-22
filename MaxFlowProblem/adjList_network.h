#pragma once
#include "network_base.h"
#include "network_params.h"
#include "adj_list.h"

class adjList_network : public network_base
{
public:
	explicit adjList_network(network_params params, adj_list network);

	adj_list get_network() const;

private:
	adj_list network;
};

