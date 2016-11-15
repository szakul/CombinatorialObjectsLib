#pragma once

#include <set>
#include <list>
#include <vector>
//#include "NumeralSystem.h"

namespace CombinatorialObjectsLib
{
	template<typename Type = int>
	class PermutationGenerator_Lexicographic_noReps
	{
	private:
		std::set<Type> elements;

		static typename std::vector<Type>::iterator FindLeastElementGreatherThan(typename std::vector<Type>::iterator begin, typename std::vector<Type>::iterator end);
		static typename std::vector<Type>::reverse_iterator FindFirstIndexToChange(std::vector<Type>& permutation);
	public:
		PermutationGenerator_Lexicographic_noReps() {}
		PermutationGenerator_Lexicographic_noReps(std::set<Type> elements) { this->elements = elements; }
		~PermutationGenerator_Lexicographic_noReps() {}
		inline unsigned long long NumberOfAllPermutations() const;
		std::vector<Type> GenerateNthPermutation(unsigned long long n) const;
		std::vector<std::vector<Type>> GenerateAllPermutations() const;
		std::vector<Type> GenerateRandomPermutation() const;
		std::vector<Type> GenerateNextPermutation(const std::vector<Type>& permutation) const;
	};

	template<typename Type>
	inline unsigned long long PermutationGenerator_Lexicographic_noReps<Type>::NumberOfAllPermutations() const
	{
		return CombinatorialObjectsLib::Extras::Math::Factorial(elements.size());
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Lexicographic_noReps<Type>::GenerateNthPermutation(unsigned long long n) const
	{
		using namespace Extras;
		using namespace NumberRepresentation;
		if (n >= NumberOfAllPermutations())
			throw std::invalid_argument("N is too large");

		std::vector<Type> permutation;
		std::vector<Type> elements = std::vector<Type>(this->elements.begin(), this->elements.end());
		NaturalNumberRepresentation inversionTable(n, elements.size(), new Factoradic());
		std::vector<Type>::iterator it;

		for (int index = inversionTable.length() - 1; index >= 0; index--)
		{
			it = elements.begin() + inversionTable[index];
			permutation.push_back(*it);
			elements.erase(it);
		}
		return permutation;
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Lexicographic_noReps<Type>::GenerateRandomPermutation() const
	{
		return GenerateNthPermutation(rand() % NumberOfAllPermutations());
	}

	template<typename Type>
	std::vector<std::vector<Type>>  PermutationGenerator_Lexicographic_noReps<Type>::GenerateAllPermutations() const
	{
		std::vector<Type> nextPermutation = std::vector<Type>(elements.begin(), elements.end());
		std::vector<std::vector<Type>> permutationsVector = { nextPermutation };
		for (unsigned long long i = 0; i < NumberOfAllPermutations() - 1; i++)
		{
			nextPermutation = GenerateNextPermutation(nextPermutation);
			permutationsVector.push_back(nextPermutation);
		}
		return permutationsVector;
	}

	template <typename Type>
	std::vector<Type> PermutationGenerator_Lexicographic_noReps<Type>::GenerateNextPermutation(const std::vector<Type>& permutation) const
	{
		std::vector<Type> nextPermutation = permutation;
		std::vector<Type>::iterator min_index, index;
		std::vector<Type>::reverse_iterator r_index = FindFirstIndexToChange(nextPermutation);

		if (r_index == nextPermutation.rend())
			throw std::invalid_argument("Permutation passed in argument is last permutation");

		index = r_index.base() - 1;
		min_index = FindLeastElementGreatherThan(index, nextPermutation.end());
		std::iter_swap(index, min_index);
		std::reverse(index + 1, nextPermutation.end());
		return nextPermutation;
	}

	template<typename Type>
	typename std::vector<Type>::reverse_iterator PermutationGenerator_Lexicographic_noReps<Type>::FindFirstIndexToChange(std::vector<Type>& permutation)
	{
		std::vector<Type>::reverse_iterator index = permutation.rend();
		std::vector<Type>::iterator it;
		Type prev_value;

		if (permutation.size() > 1)
		{
			index = ++permutation.rbegin();
			prev_value = *(permutation.rbegin());

			while ((index != permutation.rend()) && (*index > prev_value))
			{
				prev_value = *index;
				index++;
			}
		}
		return index;
	}

	template<typename Type>
	typename std::vector<Type>::iterator PermutationGenerator_Lexicographic_noReps<Type>::FindLeastElementGreatherThan(typename std::vector<Type>::iterator begin, typename std::vector<Type>::iterator end)
	{
		std::vector<Type>::iterator min_it = begin + 1;
		for (std::vector<Type>::iterator it = min_it; it != end; it++)
		{
			if ((*it > *begin) && (*it < *min_it))
			{
				min_it = it;
			}
		}
		return min_it;
	}
}

