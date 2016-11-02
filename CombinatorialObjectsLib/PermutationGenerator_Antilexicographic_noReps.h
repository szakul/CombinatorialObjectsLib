#pragma once

#include <set>
#include <vector>

namespace CombinatorialObjects
{
	template<typename Type = int>
	class PermutationGenerator_Antilexicographic_noReps
	{
	private:
		std::set<Type> elements;

		static typename std::vector<Type>::iterator FindGreatestElementLessThan(typename std::vector<Type>::iterator begin, typename std::vector<Type>::iterator end);
		static typename std::vector<Type>::iterator FindFirstIndexToChange(std::vector<Type>& permutation);
	public:
		PermutationGenerator_Antilexicographic_noReps() {}
		PermutationGenerator_Antilexicographic_noReps(std::set<Type> elements) { this->elements = elements; }
		~PermutationGenerator_Antilexicographic_noReps() {}
		inline unsigned long long NumberOfAllPermutations() const;
		std::vector<Type> GenerateNthPermutation(unsigned long long n) const;
		std::vector<std::vector<Type>> GenerateAllPermutations() const;
		std::vector<Type> GenerateRandomPermutation() const;
		std::vector<Type> GenerateNextPermutation(const std::vector<Type>& permutation) const;
	};

	template<typename Type>
	inline unsigned long long PermutationGenerator_Antilexicographic_noReps<Type>::NumberOfAllPermutations() const
	{
		return Math::Factorial(elements.size());
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Antilexicographic_noReps<Type>::GenerateNthPermutation(unsigned long long n) const
	{
		using namespace Extras;
		using namespace NumberRepresentation;
		if (n >= NumberOfAllPermutations())
			throw std::invalid_argument("N is too large");

		std::vector<Type> permutation;
		std::vector<Type> elements = std::vector<Type>(this->elements.begin(), this->elements.end());
		NaturalNumberRepresentation inversionTable(n, elements.size(), new Factoradic());
		std::vector<Type>::iterator it;
		unsigned int index = 0;

		for (int i = inversionTable.length() - 1; i >= 0; i--)
		{
			index = elements.size() - inversionTable[i] - 1;
			it = elements.begin() + index;
			permutation.insert(permutation.begin(), *it);
			elements.erase(it);
		}
		return permutation;
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Antilexicographic_noReps<Type>::GenerateNextPermutation(const std::vector<Type>& permutation) const
	{
		std::vector<Type> nextPermutation = permutation;
		std::vector<Type>::iterator max_index;
		std::vector<Type>::iterator index = FindFirstIndexToChange(nextPermutation);

		if (index == nextPermutation.end())
			throw std::invalid_argument("Permutation passed in argument is last permutation");
		max_index = FindGreatestElementLessThan(nextPermutation.begin(), index);
		std::iter_swap(index, max_index);
		std::reverse(nextPermutation.begin(), index);
		return nextPermutation;
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Antilexicographic_noReps<Type>::GenerateRandomPermutation() const
	{
		return GenerateNthPermutation(rand() % NumberOfAllPermutations());
	}

	template<typename Type>
	typename std::vector<Type>::iterator PermutationGenerator_Antilexicographic_noReps<Type>::FindGreatestElementLessThan(typename std::vector<Type>::iterator begin, typename std::vector<Type>::iterator end)
	{
		typename std::vector<Type>::iterator max_it;
		for (std::vector<Type>::iterator it = begin; it != end; it++)
		{
			if (*it < *end)
			{
				if (max_it._Ptr == nullptr)
					max_it = it;
				else if (*it > *max_it)
				{
					max_it = it;
				}
			}
		}
		return max_it;
	}

	template<typename Type>
	typename std::vector<Type>::iterator PermutationGenerator_Antilexicographic_noReps<Type>::FindFirstIndexToChange(std::vector<Type>& permutation)
	{
		typename std::vector<Type>::iterator index = permutation.end();
		typename std::vector<Type>::iterator it;
		Type prev_value;

		if (permutation.size() > 1)
		{
			index = ++permutation.begin();
			prev_value = *(permutation.begin());

			while ((index != permutation.end()) && (*index < prev_value))
			{
				prev_value = *index;
				index++;
			}
		}
		return index;
	}


	template<typename Type>
	std::vector<std::vector<Type>>  PermutationGenerator_Antilexicographic_noReps<Type>::GenerateAllPermutations() const
	{
		std::vector<Type> nextPermutation = std::vector<Type>(elements.begin(), elements.end());;
		std::vector<std::vector<Type>> permutationsVector = { nextPermutation };
		for (unsigned long long i = 0; i < NumberOfAllPermutations() - 1; i++)
		{
			nextPermutation = GenerateNextPermutation(nextPermutation);
			permutationsVector.push_back(nextPermutation);
		}
		return permutationsVector;
	}
}
