#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjects::Extras;

namespace CombinatorialObjectsLibTests
{
	TEST_CLASS(Math_Tests)
	{
		public:
			TEST_METHOD(NewtonSymbol_OrdinaryCase_Calculated)
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
				try
				{
					Math::NewtonSymbol(5, 6);
					Assert::Fail();
				}
				catch (std::invalid_argument& exception)
				{
					Assert::AreEqual(exception.what(), "K is greather than N");
				}
				catch (...)
				{
					Assert::Fail();
				}
			}
	};

	//TEST_CLASS(Codes_Tests)
	//{
	//	public:
	//		TEST_METHOD(uIntToBinaryCode_OrdinaryCase_Calculated)
	//		{
	//			std::vector<bool> Expected_Result = { 0,1,0 };
	//			Assert::IsTrue(Codes::uIntToBinaryCode(2, 3) == Expected_Result);
	//		}
	//		TEST_METHOD(uIntToFactoradic_OrdinaryCase_Calculated)
	//		{
	//			CombinatorialObjects::InversionTable Expected_Result = {0,1,1};
	//			Assert::IsTrue(Codes::uIntToFactoradic(3, 3) == Expected_Result);	
	//		}
	//};
}