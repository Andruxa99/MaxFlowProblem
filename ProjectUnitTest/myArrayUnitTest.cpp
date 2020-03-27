#include "pch.h"
#include "CppUnitTest.h"
#include "../MaxFlowProblem/myArray.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectUnitTests
{
	TEST_CLASS(myArrayUnitTests)
	{
	private:
		const size_t size = 5;
		const int value = 10;
	public:
		TEST_METHOD(should_create_array_with_zero_length)
		{
			myArray<int> array;
			Assert::AreEqual(0, (int)array.getSize());
		}

		TEST_METHOD(should_create_array_with_non_zero_length)
		{
			myArray<int> array(size);
			Assert::AreEqual(size, array.getSize());
		}

		TEST_METHOD(should_get_values_by_index)
		{
			myArray<int> array(size);
			Assert::AreEqual(0, array[0]);
			Assert::AreEqual(0, array[size / 2]);
			Assert::AreEqual(0, array[size - 1]);
		}

		TEST_METHOD(should_set_values_by_index)
		{
			myArray<int> array(size);
			Assert::AreEqual(value, array[0] = value);
			Assert::AreEqual(value, array[size / 2] = value);
			Assert::AreEqual(value, array[size - 1] = value);
		}

		TEST_METHOD(should_create_array_with_initialization)
		{
			myArray<int> array(size, value);
			for (size_t i = 0; i < size; i++)
				Assert::AreEqual(value, array[i]);
		}

		TEST_METHOD(should_fill_array)
		{
			myArray<int> array(size, value);
			array.fill(value * 2);
			for (size_t i = 0; i < size; i++)
				Assert::AreEqual(value * 2, array[i]);
		}

		TEST_METHOD(should_have_a_valid_copy_constructor)
		{
			myArray<int> array(size, value);
			auto copy_array = myArray<int>(array);
			for (size_t i = 0; i < size; i++)
				Assert::AreEqual(array[i], copy_array[i]);
		}

		TEST_METHOD(should_have_a_valid_assignment_operator)
		{
			myArray<int> array(size, value);
			myArray<int> other_array(size / 2, value * 2);
			other_array = array;
			for (size_t i = 0; i < size; i++)
				Assert::AreEqual(other_array[i], array[i]);
		}
	};
}
