#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"

//TODO Add test module organisation
//TODO Add traits to test modules and classes:
   /*	Test modules -> namespace tests
	*
	*
	*
	*/
	


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjects;

namespace CombinatorialObjectsLibTests
{
	TEST_CLASS(CombinationGenerator_noReps_Tests)
	{
		public:

			TEST_METHOD(GenerateNthSubset_OrdinaryCase_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::set<char> ExpectedResult = { 'A', 'C' };
				CombinationGenerator_noReps<char> _Generator(Elements);

				Assert::IsTrue(_Generator.GenerateNthSubset(5) == ExpectedResult);
			}
			TEST_METHOD(GenerateNthCombination_KAndNHaveProperValues_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::set<char> ExpectedResult = { 'B', 'C' };
				CombinationGenerator_noReps<char> _Generator(Elements);

				Assert::IsTrue(_Generator.GenerateNthCombination(2, 2) == ExpectedResult);
			}
			TEST_METHOD(GenerateNthCombination_KGreatherThanElementsSize_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				CombinationGenerator_noReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateNthCombination(4,4);
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
			TEST_METHOD(GenerateNthCombination_FromEmptySet_EmptySetReturned)
			{
				std::set<char> Elements = {};
				std::set<char> ExpectedResult = {};
				CombinationGenerator_noReps<char> _Generator(Elements);

				Assert::IsTrue(_Generator.GenerateNthCombination(0,0) == ExpectedResult);
			}
			TEST_METHOD(GenerateNthCombination_NIsGreatherThanNewtonSymbolFromElementsSizeAndK_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C', 'D', 'E' };
				CombinationGenerator_noReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateNthCombination(60, 2);
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
				
				CombinationGenerator_noReps<char> _Generator(Elements);
				Assert::IsTrue(_Generator.GenerateAllSubsets() == ExpectedResult);
			}
			TEST_METHOD(GenerateAllCombinations_FromEmptySet_SetWith1ElementWchichIsEmptySetReturned)
			{
				std::set<char> Elements = {};
				std::set<std::set<char>> ExpectedResult = { {} };

				CombinationGenerator_noReps<char> _Generator(Elements);
				Assert::IsTrue(_Generator.GenerateAllCombinations(0) == ExpectedResult);
			}
			TEST_METHOD(GenerateAllCombinations_KHasProperValue_BasicTest)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::set<std::set<char>> ExpectedResult = {
				{ 'A', 'B' },
				{ 'A', 'C' },
				{ 'B', 'C' } };

				CombinationGenerator_noReps<char> _Generator(Elements);

				Assert::IsTrue(_Generator.GenerateAllCombinations(2) == ExpectedResult);
			}
			TEST_METHOD(GenerateAllCombinations_KIs0_ReturnsEmptySet)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::set<std::set<char>> ExpectedResult = { {} };

				CombinationGenerator_noReps<char> _Generator(Elements);

				Assert::IsTrue(_Generator.GenerateAllCombinations(0) == ExpectedResult);

			}
			TEST_METHOD(GenerateAllCombinations_KGreatherThanElementsSize_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				CombinationGenerator_noReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateAllCombinations(4);
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
			TEST_METHOD(GenerateRandomSubset_OrdinaryCase_Calculated) 
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::set<char> Elements_temp = Elements;
				CombinationGenerator_noReps<char> _Generator(Elements);

				std::set<char> Result = _Generator.GenerateRandomSubset();
				for (std::set<char>::iterator it = Result.begin(); it != Result.end(); it++)
				{
					Elements_temp.insert(*it);
				}
				
				Assert::IsTrue(Elements.size() == Elements_temp.size());
			}
			TEST_METHOD(GenerateRandomCombination_KHasProperValue_Calculated)
			{
				unsigned int K = 2;
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::set<char> Elements_temp = Elements;
				CombinationGenerator_noReps<char> _Generator(Elements);

				std::set<char> Result = _Generator.GenerateRandomCombination(K);
				for (std::set<char>::iterator it = Result.begin(); it != Result.end(); it++)
				{
					Elements_temp.insert(*it);
				}

				Assert::IsTrue((Elements.size() == Elements_temp.size()) && (Result.size() == K));
			}
	};
}