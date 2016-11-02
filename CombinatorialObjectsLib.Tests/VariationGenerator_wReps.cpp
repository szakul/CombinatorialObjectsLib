#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjects;

namespace CombinatorialObjectsLibTests
{
	TEST_CLASS(VariationGenerator_wReps_Tests)
	{
		BEGIN_TEST_CLASS_ATTRIBUTE(VariationGenerator_wReps_Tests)
			TEST_CLASS_ATTRIBUTE(L"Namespace", L"CombinatorialObjects")
			TEST_CLASS_ATTRIBUTE(L"Namespace", L"Extras")
		END_TEST_CLASS_ATTRIBUTE()

		public:
			TEST_METHOD(GenerateAllVariations_KHasProperValue_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::vector<std::vector<char>> Expected_Result = {
				{'A', 'A'},
				{'A', 'B'},
				{'A', 'C'},
				{'B', 'A'},
				{'B', 'B'},
				{'B', 'C'},
				{'C', 'A'},
				{'C', 'B'},
				{'C', 'C'},
				};

				VariationGenerator_wReps<char> _Generator(Elements);
				Assert::IsTrue(Expected_Result == _Generator.GenerateAllVariations(2));
			}
			TEST_METHOD(GenerateAllVariations_KIsGreatherThanElementsSize_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				VariationGenerator_wReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateAllVariations(4);
					Assert::Fail();
				}
				catch (std::invalid_argument& exception)
				{
					Assert::AreEqual(exception.what(), "K is too large");
				}
				catch (...)
				{
					Assert::Fail();
				}
			}
			TEST_METHOD(GenerateAllVariations_FromEmptySet_VariationsSetWith1ElementWchichIsEmptyVectorReturned)
			{
				std::set<char> Elements = {};
				std::vector<std::vector<char>> Expected_Result = {
					{ },
				};

				VariationGenerator_wReps<char> _Generator(Elements);
				Assert::IsTrue(Expected_Result == _Generator.GenerateAllVariations(0));
			}
			TEST_METHOD(GenerateNthVariation_NIsGreatherThanNumberOfAllVariationsWithKElements_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				VariationGenerator_wReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateNthVariation(9, 2);
					Assert::Fail();
				}
				catch (std::invalid_argument& exception)
				{
					Assert::AreEqual(exception.what(), "N is too large");
				}
				catch (...)
				{
					Assert::Fail();
				}
			}
			/*
			TEST_METHOD(GenerateNthVariation_KIsGreatherThanElementsSize_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				VariationGenerator_wReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateNthVariation(8, 4);
					Assert::Fail();
				}
				catch (std::invalid_argument& exception)
				{
					Assert::AreEqual(exception.what(), "K is too large");
				}
				catch (...)
				{
					Assert::Fail();
				}
			} */
			TEST_METHOD(GenerateNthVariation_NAndKHaveProperValues_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				VariationGenerator_wReps<char> _Generator(Elements);
				std::vector<char> Expected_Result = {'A', 'C', 'A'};

				Assert::IsTrue(Expected_Result == _Generator.GenerateNthVariation(6, 3));
			}
			TEST_METHOD(GenerateNthVariation_FromEmptySet_ReturnEmptyVector)
			{
				std::set<char> Elements = {};
				std::vector<char> Expected_Result = {};
				VariationGenerator_wReps<char> _Generator(Elements);
				
				Assert::IsTrue(Expected_Result == _Generator.GenerateNthVariation(0, 0));
			}
			TEST_METHOD(GenerateNextVariation_NAndKHaveProperValues_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				VariationGenerator_wReps<char> _Generator(Elements);
				std::vector<char> Variation = { 'A', 'C', 'C' };
				std::vector<char> NextVariation = {'B', 'A', 'A'};

				Assert::IsTrue(NextVariation == _Generator.GenerateNextVariation(Variation, 3));
			}

		
	};
}