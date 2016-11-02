#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjects;
using namespace Extras;

namespace CombinatorialObjectsTests
{

	TEST_CLASS(PermutationGenerator_Lexicographic_noRepetitions_Tests)
	{
		
		public:
			TEST_METHOD(GenerateNthPermutation_NHasProperValue_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C', 'D' };
				std::vector<char> Expected_Result = { 'A', 'C', 'D', 'B' };

				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);
				Assert::IsTrue(_Generator.GenerateNthPermutation(3) == Expected_Result);
			}

			TEST_METHOD(GenerateNthPermutation_NGreaterThanSizeFactorial_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C', 'D' };
				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateNthPermutation(Math::Factorial(Elements.size()));
					Assert::Fail();
				}
				catch (std::invalid_argument& ex)
				{
					Assert::AreEqual(ex.what(), "N is too large");
				}
				catch (...)
				{
					Assert::Fail();
				}
			}

			TEST_METHOD(GenerateNthPermutation_FromEmptySet_ReturnEmptyPermutation)
			{
				std::set<char> Elements;
				std::vector<char> ExpectedResult;
				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);

				Assert::IsTrue(_Generator.GenerateNthPermutation(0) == ExpectedResult);
			}

			TEST_METHOD(GenerateAllPermutations_OrdinaryCase_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C' };
				std::vector<std::vector<char>> Expected_Result = {
				{ 'A', 'B', 'C' },
				{ 'A', 'C', 'B' },
				{ 'B', 'A', 'C' },
				{ 'B', 'C', 'A' },
				{ 'C', 'A', 'B' },
				{ 'C', 'B', 'A' } 
				};


				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);
				Assert::IsTrue(_Generator.GenerateAllPermutations() == Expected_Result);
			}

			TEST_METHOD(GenerateAllPermutations_FromEmptySet_ReturnPermutationsSetWithOneElementWhichIsEmptyPermutation)
			{
				std::set<char> Elements;
				std::vector<char> PermutationWith0Elements;
				std::vector<std::vector<char>> ExpectedResult = { PermutationWith0Elements };

				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);
				Assert::IsTrue(_Generator.GenerateAllPermutations() == ExpectedResult);
			}

			TEST_METHOD(GenerateRandomPermutation_OrdinaryCase_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C', 'D' };
				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);

				std::vector<char> Result = _Generator.GenerateRandomPermutation();
				Assert::IsTrue(std::set<char>(Result.begin(), Result.end()) == Elements);
			}
			TEST_METHOD(GenerateNextPermutation_PermutationInArgumentIsValid_Calculated)
			{
				std::set<char> Elements = { 'A', 'B', 'C', 'D' };
				std::vector<char> Permutation = { 'B', 'D', 'C', 'A' };
				std::vector<char> Expected_Result = { 'C', 'A', 'B', 'D' };

				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);
				Assert::IsTrue(_Generator.GenerateNextPermutation(Permutation) == Expected_Result);
			}
			TEST_METHOD(GenerateNextPermutation_PermutationInArgumentIsLast_ExceptionThrown)
			{
				std::set<char> Elements = { 'A', 'B', 'C', 'D' };
				std::vector<char> Permutation = { 'D', 'C', 'B', 'A' };
				PermutationGenerator_Lexicographic_noReps<char> _Generator(Elements);

				try
				{
					_Generator.GenerateNextPermutation(Permutation);
					Assert::Fail();
				}
				catch (std::invalid_argument& ex)
				{
					Assert::AreEqual(ex.what(), "Permutation passed in argument is last permutation");
				}
				catch (...)
				{
					Assert::Fail();
				}
			}
			
	};
}