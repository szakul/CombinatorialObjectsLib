#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"
#include <functional>
#include <stdexcept>
#include <algorithm>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjectsLib::Extras;

namespace CombinatorialObjectsLibTests
{
	TEST_CLASS(MathFormulas_Tests)
	{

		BEGIN_TEST_CLASS_ATTRIBUTE(MathFormulas_Tests)
			TEST_CLASS_ATTRIBUTE(L"Refactorized", L"Yes")
			END_TEST_CLASS_ATTRIBUTE()
	public:
		TEST_METHOD(NewtonSymbol_ValidArguments_Calculated)
		{
			Assert::AreEqual(Math::NewtonSymbol(5, 2), (unsigned int)10);
		}
		TEST_METHOD(NewtonSymbol_KEquals0_Return1)
		{
			Assert::AreEqual(Math::NewtonSymbol(5, 0), (unsigned int)1);
		}
		TEST_METHOD(NewtonSymbol_ParametersAreEqual_Return1)
		{
			Assert::AreEqual(Math::NewtonSymbol(5, 5), (unsigned int)1);
		}
		TEST_METHOD(NewtonSymbol_KGreatherThanN_ExceptionThrown)
		{
			std::function<unsigned int(void)> functor = [] {return Math::NewtonSymbol(5, 6); };
			Assert::ExpectException<std::invalid_argument>(functor, L"K is greather than N");
		}
		TEST_METHOD(Factorial_Nequals0_Return1)
		{
			Assert::AreEqual(Math::Factorial(0), (unsigned long long)1);
		}
		TEST_METHOD(Factorial_ValidArgument_Calculated)
		{
			Assert::AreEqual(Math::Factorial(5), (unsigned long long)120);
		}
	};
}