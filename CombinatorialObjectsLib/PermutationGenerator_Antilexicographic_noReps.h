#pragma once

#include <set>
#include <vector>

namespace CombinatorialObjects
{
	template<typename Type = int>
	class PermutationGenerator_Antilexicographic_noReps
	{
		private:
			std::set<Type> Elements;

			static typename std::vector<Type>::iterator FindGreatestElementLessThan(typename std::vector<Type>::iterator _begin, typename std::vector<Type>::iterator _end) ;
			static typename std::vector<Type>::iterator FindFirstIndexToChange(std::vector<Type>& _Permutation) ;
		public:
			PermutationGenerator_Antilexicographic_noReps() {}
			PermutationGenerator_Antilexicographic_noReps(std::set<Type> _Elements) { Elements = _Elements; }
			~PermutationGenerator_Antilexicographic_noReps() {}
			std::vector<Type> GenerateNthPermutation(unsigned long long N) const;
			std::vector<std::vector<Type>> GenerateAllPermutations() const;
			std::vector<Type> GenerateRandomPermutation() const;
			std::vector<Type> GenerateNextPermutation(std::vector<Type> _Permutation) const;
	};

	template<typename Type>
	std::vector<Type> PermutationGenerator_Antilexicographic_noReps<Type>::GenerateNthPermutation(unsigned long long N) const
	{
		if (N >= Extras::Math::Factorial(Elements.size()))
			throw std::invalid_argument("N is too large");

		std::vector<Type> _Permutation;
		std::vector<Type> _Elements = std::vector<Type>(Elements.begin(), Elements.end());
		Extras::NumberRepresentation::NaturalNumberRepresentation A(N, Elements.size(), new Extras::NumberRepresentation::Factoradic());
		//InversionTable _InversionTable = Extras::Codes::uIntToFactoradic(N, Elements.size());
		std::vector<Type>::iterator it;
		unsigned int index = 0;

		for (int i = A.length() - 1; i >= 0; i--)
		{
			index = _Elements.size() - A[i] - 1;
			it = _Elements.begin() + index;
			_Permutation.insert(_Permutation.begin(), *it);
			_Elements.erase(it);
		}
		return _Permutation;
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Antilexicographic_noReps<Type>::GenerateNextPermutation(std::vector<Type> _Permutation) const
	{
		std::vector<Type> NextPermutation = _Permutation;
		std::vector<Type>::iterator max_index;
		std::vector<Type>::iterator index = FindFirstIndexToChange(NextPermutation);

		if (index == NextPermutation.end())
			throw std::invalid_argument("Permutation passed in argument is last permutation");
		max_index = FindGreatestElementLessThan(NextPermutation.begin(), index);
		std::iter_swap(index, max_index);
		std::reverse(NextPermutation.begin(), index);
		return NextPermutation;
	}

	template<typename Type>
	std::vector<Type> PermutationGenerator_Antilexicographic_noReps<Type>::GenerateRandomPermutation() const
	{
		return GenerateNthPermutation(rand() % Extras::Math::Factorial(Elements.size()));
	}

	template<typename Type>
	typename std::vector<Type>::iterator PermutationGenerator_Antilexicographic_noReps<Type>::FindGreatestElementLessThan(typename std::vector<Type>::iterator _begin, typename std::vector<Type>::iterator _end) 
	{
		typename std::vector<Type>::iterator max_it;
		for (std::vector<Type>::iterator it = _begin; it != _end; it++)
		{
			if (*it < *_end)
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
	typename std::vector<Type>::iterator PermutationGenerator_Antilexicographic_noReps<Type>::FindFirstIndexToChange(std::vector<Type>& _Permutation) 
	{
		typename std::vector<Type>::iterator index = _Permutation.end();
		typename std::vector<Type>::iterator it;
		Type prev_value;

		if (_Permutation.size() > 1)
		{
			index = ++_Permutation.begin();
			prev_value = *(_Permutation.begin());

			while ((index != _Permutation.end()) && (*index < prev_value))
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
		std::vector<Type> NextPermutation = std::vector<Type>(Elements.begin(), Elements.end());
		std::vector<std::vector<Type>> PermutationsVector = { NextPermutation };
		for (unsigned long long i = 0; i < Extras::Math::Factorial(Elements.size()) - 1; i++)
		{
			NextPermutation = GenerateNextPermutation(NextPermutation);
			PermutationsVector.push_back(NextPermutation);
		}
		return PermutationsVector;
	}
}
