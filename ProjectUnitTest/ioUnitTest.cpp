#include "pch.h"
#include "CppUnitTest.h"
#include "../MaxFlowProblem/matrix_io.cpp"
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
		TEST_METHOD(should_read_from_file)
		{
			int v, e, source, dest;
			matrix<int> src_matrix(n + 1, n + 1, value), new_matrix;

			matrix_io io("../ProjectUnitTest/testInput.txt", "../ProjectUnitTest/outputInput.txt");
			io.read(new_matrix, v, e, source, dest);

			Assert::AreEqual(n, v);
			Assert::AreEqual(n * n, e);
			Assert::AreEqual(1, source);
			Assert::AreEqual(n, dest);
			for (size_t i = 1; i < new_matrix.getXSize(); i++)
				for (size_t j = 1; j < new_matrix.getYSize(); j++)
					Assert::AreEqual(src_matrix[i][j], new_matrix[i][j]);
		}
	};
}