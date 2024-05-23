#include "pch.h"
#include "CppUnitTest.h"
#include "../PRR_12.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(isSquareOrCube(4), true);
			Assert::AreEqual(isSquareOrCube(8), false);
		}
	};
}
