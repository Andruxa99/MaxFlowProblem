#include "network_base.h"

network_base::network_base(network_params params)
	: params(params) {}

network_base::~network_base() {}

network_params network_base::get_params() const
{
	return params;
}

int network_base::find_max_flow(IMaxFlowFinder finder)
{
	return finder.solve();
}