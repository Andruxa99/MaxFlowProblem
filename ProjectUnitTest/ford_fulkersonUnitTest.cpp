#include "pch.h"
#include "CppUnitTest.h"
#include "../MaxFlowProblem/matrix_ff.cpp"
#include "../MaxFlowProblem/ford_fulkerson.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(ford_fulkersonUnitTests)
	{
	public:
		TEST_METHOD(should_return_the_correct_result1)
		{
			int v = 6, e = 8, source = 1, dest = 6;
			matrix<int> matrix(v + 1, v + 1);
			matrix[1][2] = 3;
			matrix[1][3] = 3;
			matrix[2][3] = 2;
			matrix[2][4] = 3;
			matrix[3][5] = 2;
			matrix[4][5] = 4;
			matrix[4][6] = 2;
			matrix[5][6] = 3;
			matrix_ff matrix_ff(matrix, v, e, source, dest);
			Assert::AreEqual(5, matrix_ff.solve());
		}

		TEST_METHOD(should_return_the_correct_result2)
		{
			int v = 6, e = 9, source = 1, dest = 6;
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
			matrix_ff matrix_ff(matrix, v, e, source, dest);
			Assert::AreEqual(19, matrix_ff.solve());
		}

		TEST_METHOD(should_return_the_correct_result3)
		{
			int v = 4, e = 5, source = 1, dest = 4;
			matrix<int> matrix(7, 7);
			matrix[1][2] = 1000;
			matrix[1][3] = 1000;
			matrix[2][3] = 1;
			matrix[2][4] = 1000;
			matrix[3][4] = 1000;
			matrix_ff matrix_ff(matrix, v, e, source, dest);
			Assert::AreEqual(2000, matrix_ff.solve());
		}
	};
}