#pragma once
#include <ctime>
#include <string>

class IMaxFlowFinder
{
public:
	virtual int solve();
	virtual std::string get_name();
	time_t get_running_time();
protected:
	time_t startSearchTime;
	time_t endSearchTime;
	std::string name;
};

