#include "matrix_network.h"

matrix_network::matrix_network(network_params params, matrix<int> network)
	: network_base(params), network(network) {}

matrix<int> matrix_network::get_network() const
{
	return network;
}
