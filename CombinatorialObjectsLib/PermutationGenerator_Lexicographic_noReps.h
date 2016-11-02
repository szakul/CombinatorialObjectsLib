#pragma once

#include <set>
#include <vector>

namespace CombinatorialObjects
{
	template<typename Type = int>
	class PermutationGenerator_Lexicographic_noReps
	{
		private:
			std::set<Type> Elements;

			static typename std::vector<Type>::iterator FindLeastElementGreatherThan(typename std::vector<Type>::iterator _begin, typename std::vector<Type>::iterator _end) ;
			static typename std::vector<Type>::reverse_iterator FindFirstIndexToChange(std::vector<Type>& _Permutation) ;
		public:
			PermutationGenerator_Lexicographic_noReps() {}
			PermutationGenerator_Lexicographic_noReps(std::set<Type> _Elements) { Elements = _Elements; }
			~PermutationGenerator_Lexicographic_noReps() {}
			std::vector<Type> GenerateNthPermutation(unsigned long long N) const;
			std::vector<std::vector<Type>> GenerateAllPermutations() const;
			std::vector<Type> GenerateRandomPermutation() const;
			std::vector<Type> GenerateNextPermutation(std::vector<Type> _Permutation) const;
	};

	template<typename Type>
	std::vector<Type> PermutationGenerator_Lexicographic_noReps<Type>::GenerateNthPermutation(unsigned long long N) const
	{
		if (N >= Extras::Math::Factorial(Elements.size()))
			throw std::invalid_argument("N is too large");

		std::vector<Type> _Permutation;
		std::vector<Type> _Elements = std::vector<Type>(Elements.begin(), Elements.end());
		InversionTable _InversionTable = Extras::Codes::uIntToFactoradic(N, Elements.size());
		std::vector<Type>::iterator it;

		for (int index = _InversionTable.size() - 1; index >= 0; index--)
		{
			it = _Elements.begin() + _InversionTable[index];
			_Permutation.push_back(*it);
			_Elements.erase(it);
		}

		return _Permutation;
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Lexicographic_noReps<Type>::GenerateRandomPermutation() const
	{
		return GenerateNthPermutation(rand() % Extras::Math::Factorial(Elements.size()));
	}

	template<typename Type>
	std::vector<std::vector<Type>>  PermutationGenerator_Lexicographic_noReps<Type>::GenerateAllPermutations() const
	{
		std::vector<Type> NextPermutation = std::vector<Type>(Elements.begin(), Elements.end());
		std::vector<std::vector<Type>> PermutationsVector = { NextPermutation };
		for (unsigned long long i = 0; i < Extras::Math::Factorial(Elements.size()) - 1; i++)
		{
			NextPermutation = GenerateNextPermutation(NextPermutation);
			PermutationsVector.push_back(NextPermutation);
		}
		return PermutationsVector;
	}

	template <typename Type>
	std::vector<Type> PermutationGenerator_Lexicographic_noReps<Type>::GenerateNextPermutation(std::vector<Type> _Permutation) const
	{
		std::vector<Type> NextPermutation = (std::vector<Type>)_Permutation;
		std::vector<Type>::iterator min_index, index;
		std::vector<Type>::reverse_iterator r_index = FindFirstIndexToChange(NextPermutation);

		if (r_index == NextPermutation.rend())
			throw std::invalid_argument("Permutation passed in argument is last permutation");

		index = r_index.base() - 1;
		min_index = FindLeastElementGreatherThan(index, NextPermutation.end());
		std::iter_swap(index, min_index);
		std::reverse(index + 1, NextPermutation.end());
		return NextPermutation;
	}

	template<typename Type>
	typename std::vector<Type>::reverse_iterator PermutationGenerator_Lexicographic_noReps<Type>::FindFirstIndexToChange(std::vector<Type>& _Permutation) 
	{
		std::vector<Type>::reverse_iterator index = _Permutation.rend();
		std::vector<Type>::iterator it;
		Type prev_value;

		if (_Permutation.size() > 1)
		{
			index = ++_Permutation.rbegin();
			prev_value = *(_Permutation.rbegin());

			while ((index != _Permutation.rend()) && (*index > prev_value))
			{
				prev_value = *index;
				index++;
			}
		}
		return index;
	}

	template<typename Type>
	typename std::vector<Type>::iterator PermutationGenerator_Lexicographic_noReps<Type>::FindLeastElementGreatherThan(typename std::vector<Type>::iterator _begin, typename std::vector<Type>::iterator _end) 
	{
		std::vector<Type>::iterator min_it = _begin + 1;
		for (std::vector<Type>::iterator it = min_it; it != _end; it++)
		{
			if ((*it > *_begin) && (*it < *min_it))
			{
				min_it = it;
			}
		}
		return min_it;
	}
}

