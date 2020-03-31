#include "pch.h"
#include "CppUnitTest.h"
#include "../MaxFlowProblem/matrix_io.cpp"
#include "../MaxFlowProblem/adjList_io.cpp"
#include "../MaxFlowProblem/io.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(ioUnitTests)
	{
	private:
		const int n = 3;
		const int value = 10;
	public:
		TEST_METHOD(should_read_matrix_from_file)
		{
			int v, e, source, dest;
			matrix<int> src_matrix(n + 1, n + 1), new_matrix;
			src_matrix[1][2] = value;
			src_matrix[1][3] = value;
			src_matrix[2][3] = value;

			matrix_io io("../ProjectUnitTest/testInput.txt", "../ProjectUnitTest/testOutput.txt");
			io.read(new_matrix, v, e, source, dest);

			Assert::AreEqual(n, v);
			Assert::AreEqual(n, e);
			Assert::AreEqual(1, source);
			Assert::AreEqual(n, dest);
			for (size_t i = 1; i < new_matrix.getXSize(); i++)
				for (size_t j = 1; j < new_matrix.getYSize(); j++)
					Assert::AreEqual(src_matrix[i][j], new_matrix[i][j]);
		}

		TEST_METHOD(should_read_adjList_from_file)
		{
			int v, e, source, dest;
			graph src_list(n + 1), new_list;
			src_list[1].push_back(make_pair(2, 10));
			src_list[1].push_back(make_pair(3, 10));
			src_list[2].push_back(make_pair(1, 0));
			src_list[2].push_back(make_pair(3, 10));
			src_list[3].push_back(make_pair(1, 0));
			src_list[3].push_back(make_pair(2, 0));
			

			adjList_io io("../ProjectUnitTest/testInput.txt", "../ProjectUnitTest/testOutput.txt");
			io.read(new_list, v, e, source, dest);

			Assert::AreEqual(n, v);
			Assert::AreEqual(n, e);
			Assert::AreEqual(1, source);
			Assert::AreEqual(n, dest);
			
			for (int i = 1; i < new_list.size(); i++)
				for (int j = 1; j < new_list[i].size(); j++) {
					Assert::AreEqual(src_list[i][j].first, new_list[i][j].first);
					Assert::AreEqual(src_list[i][j].second, new_list[i][j].second);
				}
		}

		TEST_METHOD(should_write_in_file)
		{
			int v, e, source, dest;
			matrix<int> src_matrix(n + 1, n + 1), new_matrix;
			src_matrix[1][2] = value;
			src_matrix[1][3] = value;
			src_matrix[2][3] = value;

			matrix_io io("../ProjectUnitTest/testOutput.txt", "../ProjectUnitTest/testOutput.txt");
			io.write(n), io.write(n), io.write(1), io.write(n);
			io.write(src_matrix);

			io.read(new_matrix, v, e, source, dest);

			Assert::AreEqual(n, v);
			Assert::AreEqual(n, e);
			Assert::AreEqual(1, source);
			Assert::AreEqual(n, dest);
			for (size_t i = 1; i < new_matrix.getXSize(); i++)
				for (size_t j = 1; j < new_matrix.getYSize(); j++)
					Assert::AreEqual(src_matrix[i][j], new_matrix[i][j]);
		}
	};
}