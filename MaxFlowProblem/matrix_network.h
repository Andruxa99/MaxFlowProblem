#pragma once
#include "network_base.h"
#include "network_params.h"
#include "matrix.h"

class matrix_network : public network_base
{
public:
	explicit matrix_network(network_params params, matrix<int> network);

	matrix<int> get_network() const;

private:
	matrix<int> network;
};
