#include "pch.h"
#include "CppUnitTest.h"
#include <tuple>
#include "../MaxFlowProblem/network_converter.h"
#include "../MaxFlowProblem/network_generator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(network_generatorUnitTests)
	{
	private:
		int v = 5;
		int e = 10;
		int maxWeight = 10;

		network_params params{ v + 1, e, 1, v, maxWeight};
	public:
		TEST_METHOD(should_generate_network_with_right_size)
		{
			network_generator generator(params);
			auto network = generator.generate_network();
			Assert::AreEqual((int)network.size(), e);
		}

		TEST_METHOD(should_generate_network_with_expected_max_weight) {
			network_generator generator(params);
			auto network = generator.generate_network();
			for (auto edge : network)
				Assert::IsTrue(std::get<2>(edge) <= maxWeight);
		}

		TEST_METHOD(should_generate_connected_network)
		{
			network_generator generator(params);
			auto network = generator.generate_network();
			auto matrix = network_converter::to_adj_matrix(network, params);
			int comp_count = 0;
			auto visited = new bool[v + 1]{};
			for (size_t i = 1; i < v + 1; i++)
				if (!visited[i]) {
					dfs(i, visited, matrix);
					comp_count++;
				}
			Assert::AreEqual(1, comp_count);
		}

		void dfs(int v, bool *visited, const matrix<int> & network) {
			visited[v] = true;
			for (size_t i = 0; i < network.get_x_size(); i++)
				if (!visited[i] && network[v][i] > 0) dfs(i, visited, network);
		}
	};
}