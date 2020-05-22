#include "pch.h"
#include "CppUnitTest.h"
#include "../MaxFlowProblem/matrix_ff.cpp"
#include "../MaxFlowProblem/adjList_ff.cpp"
#include "../MaxFlowProblem/ford_fulkerson.cpp"
#include "../MaxFlowProblem/network_base.cpp"
#include "../MaxFlowProblem/matrix_network.cpp"
#include "../MaxFlowProblem/adjList_network.cpp"
#include "../MaxFlowProblem/IMaxFlowFinder.cpp"
#include "../MaxFlowProblem/adj_list.cpp"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(ford_fulkersonUnitTests)
	{
	public:
		TEST_METHOD(should_matrix_ff_return_the_correct_result1)
		{
			int v = 6, e = 8, source = 1, dest = 6;
			network_params params{ v,e,source,dest };
			matrix<int> matrix(v + 1, v + 1);
			matrix[1][2] = 3;
			matrix[1][3] = 3;
			matrix[2][3] = 2;
			matrix[2][4] = 3;
			matrix[3][5] = 2;
			matrix[4][5] = 4;
			matrix[4][6] = 2;
			matrix[5][6] = 3;
			matrix_network matrixNetwork(params, matrix);
			matrix_ff matrix_ff(matrixNetwork);
			Assert::AreEqual(5, matrix_ff.solve());
		}

		TEST_METHOD(should_matrix_ff_return_the_correct_result2)
		{
			int v = 6, e = 9, source = 1, dest = 6;
			network_params params{ v,e,source,dest };
			matrix<int> matrix(v + 1, v + 1);
			matrix[1][2] = 10;
			matrix[1][3] = 10;
			matrix[2][3] = 2;
			matrix[2][4] = 4;
			matrix[2][5] = 8;
			matrix[3][5] = 9;
			matrix[5][4] = 6;
			matrix[4][6] = 10;
			matrix[5][6] = 10;
			matrix_network matrixNetwork(params, matrix);
			matrix_ff matrix_ff(matrixNetwork);
			Assert::AreEqual(19, matrix_ff.solve());
		}

		TEST_METHOD(should_matrix_ff_return_the_correct_result3)
		{
			int v = 4, e = 5, source = 1, dest = 4;
			network_params params{ v,e,source,dest };
			matrix<int> matrix(v + 1, v + 1);
			matrix[1][2] = 1000;
			matrix[1][3] = 1000;
			matrix[2][3] = 1;
			matrix[2][4] = 1000;
			matrix[3][4] = 1000;
			matrix_network matrixNetwork(params, matrix);
			matrix_ff matrix_ff(matrixNetwork);
			Assert::AreEqual(2000, matrix_ff.solve());
		}

		TEST_METHOD(should_adj_ff_return_the_correct_result1)
		{
			int v = 6, e = 8, source = 1, dest = 6;
			network_params params{ v,e,source,dest };
			adj_list g(v + 1);
			g[1].push_back(make_pair(2, 3));
			g[2].push_back(make_pair(1, 0));

			g[1].push_back(make_pair(3, 3));
			g[3].push_back(make_pair(1, 0));

			g[2].push_back(make_pair(3, 2));
			g[3].push_back(make_pair(2, 0));

			g[2].push_back(make_pair(4, 3));
			g[4].push_back(make_pair(2, 0));

			g[3].push_back(make_pair(5, 2));
			g[5].push_back(make_pair(3, 0));

			g[4].push_back(make_pair(5, 4));
			g[5].push_back(make_pair(4, 0));

			g[4].push_back(make_pair(6, 2));
			g[6].push_back(make_pair(4, 0));

			g[5].push_back(make_pair(6, 3)); 
			g[6].push_back(make_pair(5, 0));
			adjList_network adjListNetwork(params, g);
			adjList_ff adjList_ff(adjListNetwork);
			Assert::AreEqual(5, adjList_ff.solve());
		}

		TEST_METHOD(should_adj_ff_return_the_correct_result2)
		{
			int v = 6, e = 9, source = 1, dest = 6;
			network_params params{ v,e,source,dest };
			adj_list g(v + 1);
			g[1].push_back(make_pair(2, 10));
			g[2].push_back(make_pair(1, 0));

			g[1].push_back(make_pair(3, 10));
			g[3].push_back(make_pair(1, 0));

			g[2].push_back(make_pair(3, 2));
			g[3].push_back(make_pair(2, 0));

			g[2].push_back(make_pair(4, 4));
			g[4].push_back(make_pair(2, 0));

			g[2].push_back(make_pair(5, 8));
			g[5].push_back(make_pair(2, 0));

			g[3].push_back(make_pair(5, 9));
			g[5].push_back(make_pair(3, 0));

			g[5].push_back(make_pair(4, 6));
			g[4].push_back(make_pair(5, 0));

			g[4].push_back(make_pair(6, 10));
			g[6].push_back(make_pair(4, 0));

			g[5].push_back(make_pair(6, 10));
			g[6].push_back(make_pair(5, 0));

			adjList_network adjListNetwork(params, g);
			adjList_ff adjList_ff(adjListNetwork);
			Assert::AreEqual(19, adjList_ff.solve());
		}

		TEST_METHOD(should_adj_ff_return_the_correct_result3)
		{
			int v = 4, e = 5, source = 1, dest = 4;
			network_params params{ v,e,source,dest };
			adj_list g(v + 1);
			g[1].push_back(make_pair(2, 1000));
			g[2].push_back(make_pair(1, 0));

			g[1].push_back(make_pair(3, 1000));
			g[3].push_back(make_pair(1, 0));

			g[2].push_back(make_pair(3, 1));
			g[3].push_back(make_pair(2, 0));

			g[2].push_back(make_pair(4, 1000));
			g[4].push_back(make_pair(2, 0));

			g[3].push_back(make_pair(4, 1000));
			g[4].push_back(make_pair(3, 0));

			adjList_network adjListNetwork(params, g);
			adjList_ff adjList_ff(adjListNetwork);
			Assert::AreEqual(2000, adjList_ff.solve());
		}
	};
}