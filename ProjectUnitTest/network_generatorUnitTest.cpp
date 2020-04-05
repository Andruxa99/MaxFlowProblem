#include "pch.h"
#include "CppUnitTest.h"
#include "../MaxFlowProblem/network_generator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(network_generatorUnitTests)
	{
	private:
		const size_t v = 5;
		const int e = 10;
		const int source = 1;
		const int dest = 5;
	public:
		TEST_METHOD(should_generate_network_with_right_size)
		{
			network_generator generator(v, e, source, dest);
			matrix<int> graph = generator.generate();
			Assert::AreEqual(graph.getXSize(), v + 1);
			Assert::AreEqual(graph.getYSize(), v + 1);
		}

		TEST_METHOD(should_generate_network_with_right_edge_number)
		{
			network_generator generator(v, e, source, dest);
			matrix<int> graph = generator.generate();
			int edge_count = 0;
			for (size_t i = 1; i < graph.getXSize(); i++)
				for (size_t j = 1; j < graph.getYSize(); j++)
					if (graph[i][j] != 0) edge_count++;

			Assert::AreEqual(edge_count, e);
		}

		TEST_METHOD(should_generate_connected_network)
		{
			network_generator generator(v, e, source, dest);
			matrix<int> graph = generator.generate();
			int comp_count = 0;
			auto visited = new bool[v + 1]{};
			for (size_t i = 1; i < v + 1; i++)
				if (!visited[i]) {
					dfs(i, visited, graph);
					comp_count++;
				}
			Assert::AreEqual(1, comp_count);
			
		}

		void dfs(int v, bool *visited, const matrix<int> &graph) {
			visited[v] = true;
			for (size_t i = 0; i < graph.getYSize(); i++)
				if (!visited[i] && graph[v][i] > 0) dfs(i, visited, graph);
		}
	};
}