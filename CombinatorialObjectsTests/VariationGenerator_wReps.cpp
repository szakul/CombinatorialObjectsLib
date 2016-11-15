#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"
#include <functional>
#include <stdexcept>
#include <algorithm>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjectsLib;

namespace CombinatorialObjectsLibTests
{
	TEST_CLASS(VariationGenerator_wReps_Tests)
	{
		BEGIN_TEST_CLASS_ATTRIBUTE(VariationGenerator_wReps_Tests)
			TEST_CLASS_ATTRIBUTE(L"Refactorized", L"No")
			END_TEST_CLASS_ATTRIBUTE()

	public:

		TEST_METHOD(GenerateAllVariations_OrdinaryCase_Calculated)
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

			VariationGenerator_wReps<char> Generator(Elements);
			Assert::IsTrue(Expected_Result == Generator.GenerateAllVariations(2));
		}
		TEST_METHOD(GenerateAllVariations_FromEmptySet_VariationsSetWith1ElementWchichIsEmptyVectorReturned)
		{
			std::set<char> Elements = {};
			std::vector<std::vector<char>> Expected_Result = { { }, };

			VariationGenerator_wReps<char> Generator(Elements);
			Assert::IsTrue(Expected_Result == Generator.GenerateAllVariations(0));
		}
		TEST_METHOD(GenerateNthVariation_NIsGreatherThanNumberOfAllVariationsWithKElements_ExceptionThrown)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			VariationGenerator_wReps<char> Generator(Elements);

			std::function<std::vector<char>(void)> functor = [&Generator] {return Generator.GenerateNthVariation(9, 2); };
			Assert::ExpectException<std::invalid_argument>(functor, L"N is too large");
		}
		TEST_METHOD(GenerateNthVariation_NHasProperValue_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			VariationGenerator_wReps<char> Generator(Elements);
			std::vector<char> Expected_Result = { 'A', 'C', 'A' };

			Assert::IsTrue(Expected_Result == Generator.GenerateNthVariation(6, 3));
		}
		TEST_METHOD(GenerateNthVariation_FromEmptySet_ReturnEmptyVector)
		{
			std::set<char> Elements = {};
			std::vector<char> Expected_Result = {};
			VariationGenerator_wReps<char> Generator(Elements);

			Assert::IsTrue(Expected_Result == Generator.GenerateNthVariation(0, 0));
		}
		TEST_METHOD(GenerateNextVariation_VariationInArgumentValid_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			std::vector<char> Variation = { 'A', 'C', 'C' };
			std::vector<char> NextVariation = { 'B', 'A', 'A' };
			VariationGenerator_wReps<char> Generator(Elements);

			Assert::IsTrue(NextVariation == Generator.GenerateNextVariation(Variation, 3));
		}
		TEST_METHOD(GenerateNextVariation_VariationInArgumentIsLastVariation_ExceptionThrown)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			std::vector<char> Variation = { 'C', 'C', 'C', 'C' };
			VariationGenerator_wReps<char> Generator(Elements);

			std::function<std::vector<char>(void)> functor = [&Generator, &Variation] {return Generator.GenerateNextVariation(Variation, 4); };
			Assert::ExpectException<std::invalid_argument>(functor, L"Variation passed in argument is last variation");
		}
		TEST_METHOD(GenerateRandomVariation_OrdinaryCase_Calculated)
		{
			//TODO implement this
			std::set<char> Elements = { 'A', 'B', 'C' };
			VariationGenerator_wReps<char> Generator(Elements);

			std::vector<char> Result = Generator.GenerateRandomVariation(4);
			std::sort(Result.begin(), Result.end());

			Assert::IsTrue(std::includes(Elements.begin(), Elements.end(), Result.begin(), Result.end()));
		}


	};
}