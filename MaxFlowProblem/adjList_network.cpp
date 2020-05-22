#include "adjList_network.h"
#include <set>

adjList_network::adjList_network(network_params params, adj_list network)
	: network_base(params), network(network) {}

adj_list adjList_network::get_network() const
{
	return network;
}
