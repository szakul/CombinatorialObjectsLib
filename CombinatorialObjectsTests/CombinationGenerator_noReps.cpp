#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"
#include <functional>
#include <stdexcept>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjectsLib;

namespace CombinatorialObjectsTests
{
	TEST_CLASS(CombinationGenerator_noReps_Tests)
	{

		BEGIN_TEST_CLASS_ATTRIBUTE(CombinationGenerator_noReps_Tests)
			TEST_CLASS_ATTRIBUTE(L"Refactorized", L"Yes")
			END_TEST_CLASS_ATTRIBUTE()

	public:
		TEST_METHOD(GenerateNthSubset_OrdinaryCase_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			std::set<char> ExpectedResult = { 'A', 'C' };
			CombinationGenerator_noReps<char> Generator(Elements);

			Assert::IsTrue(Generator.GenerateNthSubset(5) == ExpectedResult);
		}
		TEST_METHOD(GenerateNthCombination_KAndNHaveProperValues_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			std::set<char> ExpectedResult = { 'B', 'C' };
			CombinationGenerator_noReps<char> Generator(Elements);

			Assert::IsTrue(Generator.GenerateNthCombination(2, 2) == ExpectedResult);
		}
		TEST_METHOD(GenerateNthCombination_KGreatherThanElementsSize_ExceptionThrown)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			CombinationGenerator_noReps<char> Generator(Elements);

			std::function<std::set<char>(void)> functor = [&Generator] { return Generator.GenerateNthCombination(4, 4); };

			Assert::ExpectException<std::invalid_argument>(functor, L"K is too large");
		}
		TEST_METHOD(GenerateNthCombination_FromEmptySet_EmptySetReturned)
		{
			std::set<char> Elements = {};
			std::set<char> ExpectedResult = {};
			CombinationGenerator_noReps<char> Generator(Elements);

			Assert::IsTrue(Generator.GenerateNthCombination(0, 0) == ExpectedResult);
		}
		TEST_METHOD(GenerateNthCombination_NIsGreatherThanNewtonSymbolFromElementsSizeAndK_ExceptionThrown)
		{
			std::set<char> Elements = { 'A', 'B', 'C', 'D', 'E' };
			CombinationGenerator_noReps<char> Generator(Elements);

			std::function<std::set<char>(void)> functor = [&Generator] { return Generator.GenerateNthCombination(60, 2); };

			Assert::ExpectException<std::invalid_argument>(functor, L"N is too large");
		}
		TEST_METHOD(GenerateAllSubsets_OrdinaryCase_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			std::set<std::set<char>> ExpectedResult = {
			{},
			{'A'},
			{'A', 'B'},
			{'A', 'C'},
			{'A', 'B', 'C'},
			{'B'},
			{'B', 'C'},
			{'C'}, };

			CombinationGenerator_noReps<char> Generator(Elements);
			Assert::IsTrue(Generator.GenerateAllSubsets() == ExpectedResult);
		}
		TEST_METHOD(GenerateAllCombinations_FromEmptySet_SetWith1ElementWchichIsEmptySetReturned)
		{
			std::set<char> Elements = {};
			std::set<std::set<char>> ExpectedResult = { {} };

			CombinationGenerator_noReps<char> Generator(Elements);
			Assert::IsTrue(Generator.GenerateAllCombinations(0) == ExpectedResult);
		}
		TEST_METHOD(GenerateAllCombinations_KHasProperValue_BasicTest)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			std::set<std::set<char>> ExpectedResult = {
			{ 'A', 'B' },
			{ 'A', 'C' },
			{ 'B', 'C' } };

			CombinationGenerator_noReps<char> Generator(Elements);

			Assert::IsTrue(Generator.GenerateAllCombinations(2) == ExpectedResult);
		}
		TEST_METHOD(GenerateAllCombinations_KIs0_ReturnsEmptySet)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			std::set<std::set<char>> ExpectedResult = { {} };

			CombinationGenerator_noReps<char> Generator(Elements);

			Assert::IsTrue(Generator.GenerateAllCombinations(0) == ExpectedResult);

		}
		TEST_METHOD(GenerateAllCombinations_KGreatherThanElementsSize_ExceptionThrown)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			CombinationGenerator_noReps<char> Generator(Elements);

			std::function<std::set<std::set<char>>(void)> functor = [&Generator] {return Generator.GenerateAllCombinations(4); };

			Assert::ExpectException<std::invalid_argument>(functor, L"K is too large");
		}
		TEST_METHOD(GenerateRandomSubset_OrdinaryCase_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			CombinationGenerator_noReps<char> Generator(Elements);

			std::set<char> Result = Generator.GenerateRandomSubset();

			Assert::IsTrue(std::includes(Elements.begin(), Elements.end(), Result.begin(), Result.end()));
		}
		TEST_METHOD(GenerateRandomCombination_KHasProperValue_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C' };
			CombinationGenerator_noReps<char> Generator(Elements);

			std::set<char> Result = Generator.GenerateRandomCombination(2);

			Assert::IsTrue(std::includes(Elements.begin(), Elements.end(), Result.begin(), Result.end()));
		}
	};
}