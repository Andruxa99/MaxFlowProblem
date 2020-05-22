#pragma once
#include <vector>
#include "IMaxFlowFinder.h"
#include "network_params.h"

typedef std::vector<std::tuple<int, int, int>> edges_list;
class network_base
{
public:
	explicit network_base(network_params params);
	virtual ~network_base();

	network_params get_params() const;
	int find_max_flow(IMaxFlowFinder finder);

private:
	network_params params;
};

