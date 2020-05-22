#include "pch.h"
#include "CppUnitTest.h"
#include "../MaxFlowProblem/matrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(matrixUnitTests)
	{
	private:
		const size_t n = 5;
		const size_t m = 10;
		const int value = 10;
	public:
		TEST_METHOD(should_create_matrix_with_zero_length)
		{
			matrix<int> matrix;
			Assert::AreEqual(0, (int)matrix.get_x_size());
			Assert::AreEqual(0, (int)matrix.get_y_size());
		}

		TEST_METHOD(should_create_matrix_with_non_zero_length)
		{
			matrix<int> matrix(n);
			Assert::AreEqual(n, matrix.get_x_size());
			Assert::AreEqual(0, (int)matrix.get_y_size());
		}

		TEST_METHOD(should_get_values_by_index)
		{
			matrix<int> matrix(n,m);
			Assert::AreEqual(0, matrix[0][0]);
			Assert::AreEqual(0, matrix[n / 2][m / 2]);
			Assert::AreEqual(0, matrix[n - 1][m - 1]);
		}

		TEST_METHOD(should_set_values_by_index)
		{
			matrix<int> matrix(n, m);
			Assert::AreEqual(value, matrix[0][0] = value);
			Assert::AreEqual(value, matrix[n / 2][m / 2] = value);
			Assert::AreEqual(value, matrix[n - 1][m - 1] = value);
		}

		TEST_METHOD(should_create_matrix_with_initialization)
		{
			matrix<int> matrix(n, m, value);
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < m; j++)
				Assert::AreEqual(value, matrix[i][j]);
		}

		TEST_METHOD(should_fill_matrix)
		{
			matrix<int> matrix(n, m, value);
			matrix.fill(value * 2);
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < m; j++)
					Assert::AreEqual(value * 2, matrix[i][j]);
		}

		TEST_METHOD(should_have_a_valid_copy_constructor)
		{
			matrix<int> first_matrix(n, m, value);
			auto copy_matrix = matrix<int>(first_matrix);
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < m; j++)
					Assert::AreEqual(first_matrix[i][j], copy_matrix[i][j]);
		}

		TEST_METHOD(should_have_a_valid_assignment_operator)
		{
			matrix<int> first_matrix(n, m, value);
			matrix<int> other_matrix(n / 2, m / 2, value * 2);
			other_matrix = first_matrix;
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < m; j++)
					Assert::AreEqual(first_matrix[i][j], other_matrix[i][j]);
		}
	};
}
