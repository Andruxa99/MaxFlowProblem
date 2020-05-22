#include "pch.h"
#include "CppUnitTest.h"
#include <tuple>
#include "../MaxFlowProblem/network_converter.cpp"
#include "../MaxFlowProblem/network_generator.cpp"
#include "../MaxFlowProblem/matrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(network_converterUnitTest)
	{
	private:
		int v = 5;
		int e = 10;
		int maxWeight = 10;

		network_params params{ v + 1, e, 1, v, maxWeight };
	public:
		TEST_METHOD(should_convert_edges_list_to_matrix) {
			network_generator generator(params);
			auto network = generator.generate_network();
			auto matrix = network_converter::to_adj_matrix(network, params);
			for (auto edges : network) {
				int begNode, endNode, weight;
				std::tie(begNode, endNode, weight) = edges;
				Assert::AreEqual(matrix[begNode][endNode], weight);
			}
		}

		TEST_METHOD(should_convert_edges_list_to_adjacency_list) {
			network_generator generator(params);
			auto network = generator.generate_network();
			auto adjList = network_converter::to_adj_list(network, params);
			for (auto edges : network) {
				int begNode, endNode, weight;
				std::tie(begNode, endNode, weight) = edges;
				auto index = std::distance(adjList[begNode].begin(), std::find_if(adjList[begNode].begin(), adjList[begNode].end(),
					[endNode](auto i) {return i.first == endNode && i.second; }));
				Assert::AreEqual(adjList[begNode][index].second, weight);
				//Assert::AreEqual(adjList[index][begNode].second, 0);
			}
		}
	};
}
