#include "IMaxFlowFinder.h"

int IMaxFlowFinder::solve()
{
	return 0;
}

time_t IMaxFlowFinder::get_running_time()
{
	return endSearchTime - startSearchTime;
}

std::string IMaxFlowFinder::get_name()
{
	return name;
}
