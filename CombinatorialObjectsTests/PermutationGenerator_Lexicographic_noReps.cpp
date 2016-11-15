#include "stdafx.h"
#include "CppUnitTest.h"
#include "CombinatorialObjectsLib.h"
#include <functional>
#include <stdexcept>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CombinatorialObjectsLib;
using namespace CombinatorialObjectsLib::Extras;

namespace CombinatorialObjectsTests
{

	TEST_CLASS(PermutationGenerator_Lexicographic_noRepetitions_Tests)
	{
		BEGIN_TEST_CLASS_ATTRIBUTE(PermutationGenerator_Lexicographic_noRepetitions_Tests)
			TEST_CLASS_ATTRIBUTE(L"Refactorized", L"Yes")
			END_TEST_CLASS_ATTRIBUTE()

	public:

		TEST_METHOD(GenerateNthPermutation_NHasProperValue_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C', 'D' };
			std::vector<char> Expected_Result = { 'A', 'C', 'D', 'B' };

			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);
			Assert::IsTrue(Generator.GenerateNthPermutation(3) == Expected_Result);
		}

		TEST_METHOD(GenerateNthPermutation_NGreaterThanSizeFactorial_ExceptionThrown)
		{
			std::set<char> Elements = { 'A', 'B', 'C', 'D' };
			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);

			std::function<std::vector<char>(void)> functor = [&Generator] {return Generator.GenerateNthPermutation(24); };

			Assert::ExpectException<std::invalid_argument>(functor, L"N is too large");
		}

		TEST_METHOD(GenerateNthPermutation_FromEmptySet_ReturnEmptyPermutation)
		{
			std::set<char> Elements;
			std::vector<char> ExpectedResult;
			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);

			Assert::IsTrue(Generator.GenerateNthPermutation(0) == ExpectedResult);
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


			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);
			Assert::IsTrue(Generator.GenerateAllPermutations() == Expected_Result);
		}

		TEST_METHOD(GenerateAllPermutations_FromEmptySet_ReturnPermutationsSetWithOneElementWhichIsEmptyPermutation)
		{
			std::set<char> Elements;
			std::vector<char> PermutationWith0Elements;
			std::vector<std::vector<char>> ExpectedResult = { PermutationWith0Elements };

			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);
			Assert::IsTrue(Generator.GenerateAllPermutations() == ExpectedResult);
		}

		TEST_METHOD(GenerateRandomPermutation_OrdinaryCase_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C', 'D' };
			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);

			std::vector<char> Result = Generator.GenerateRandomPermutation();
			std::sort(Result.begin(), Result.end());

			Assert::IsTrue(std::includes(Elements.begin(), Elements.end(), Result.begin(), Result.end()));
		}
		TEST_METHOD(GenerateNextPermutation_PermutationInArgumentIsValid_Calculated)
		{
			std::set<char> Elements = { 'A', 'B', 'C', 'D' };
			std::vector<char> Permutation = { 'B', 'D', 'C', 'A' };
			std::vector<char> Expected_Result = { 'C', 'A', 'B', 'D' };

			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);
			Assert::IsTrue(Generator.GenerateNextPermutation(Permutation) == Expected_Result);
		}
		TEST_METHOD(GenerateNextPermutation_PermutationInArgumentIsLast_ExceptionThrown)
		{
			std::set<char> Elements = { 'A', 'B', 'C', 'D' };
			std::vector<char> Permutation = { 'D', 'C', 'B', 'A' };
			PermutationGenerator_Lexicographic_noReps<char> Generator(Elements);

			std::function<std::vector<char>(void)> functor = [&Generator, &Permutation] {return Generator.GenerateNextPermutation(Permutation); };

			Assert::ExpectException<std::invalid_argument>(functor, L"Permutation passed in argument is last permutation");
		}



	};
}