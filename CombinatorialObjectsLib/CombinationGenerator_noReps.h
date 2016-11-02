#pragma once
#include <set>

namespace CombinatorialObjects
{
	template <typename Type = int>
	class CombinationGenerator_noReps
	{
		private:
			std::set<Type> Elements;

			static std::set<Type> GetSubset(std::set<Type> _Elements, std::vector<bool> WhichElements)
			{
				if (_Elements.size() != WhichElements.size())
					throw std::length_error("Arguments sizes are not equal");

				std::set<Type>::iterator it = _Elements.begin();
				std::set<Type> Subset;

				for (int i = 0; i < WhichElements.size(); i++)
				{
					if (WhichElements[i] == 1)
					{
						Subset.insert(*it);
					}
					it++;
				}
				return Subset;
			}
		public:		
			CombinationGenerator_noReps() {}
			CombinationGenerator_noReps(std::set<Type> _Elements) : Elements(_Elements) {}
			~CombinationGenerator_noReps() {}
			size_t NumberOfAllSubsets() const;
			size_t NumberOfAllCombinations(unsigned int K) const;
			std::set<Type> GenerateNthSubset(unsigned int N) const;
			std::set<Type> GenerateNthCombination(unsigned int N, unsigned int K) const;
			std::set<std::set<Type>> GenerateAllSubsets() const;
			std::set<std::set<Type>> GenerateAllCombinations(unsigned int K) const;
			std::set<Type> GenerateRandomSubset() const;
			std::set<Type> GenerateRandomCombination(unsigned int K) const;


	};

	template <typename Type>
	size_t CombinationGenerator_noReps<Type>::NumberOfAllSubsets() const
	{
		size_t Result = 0;
		for (int i = 0; i <= Elements.size(); i++)
		{
			Result += Extras::Math::NewtonSymbol(Elements.size(), i);
		}
		return Result;
	}

	template <typename Type>
	size_t CombinationGenerator_noReps<Type>::NumberOfAllCombinations(unsigned int K) const
	{
		return Extras::Math::NewtonSymbol(Elements.size(), K);
	}

	template <typename Type>
	std::set<std::set<Type>> CombinationGenerator_noReps<Type>::GenerateAllSubsets() const
	{
		std::set<std::set<Type>> Result;
		std::set<Type> CurrentCombination;
		std::vector<std::vector<bool>> BinarySequences = Extras::BinarySequences(Elements.size());

		for (int i = 0; i < BinarySequences.size(); i++)
		{
			CurrentCombination = GetSubset(Elements, BinarySequences[i]);
			Result.insert(CurrentCombination);
		}
		return Result;
	}

	template <typename Type>
	std::set<Type> CombinationGenerator_noReps<Type>::GenerateRandomSubset() const
	{
		int N = rand() % NumberOfAllSubsets();
		return GenerateNthSubset(N);
	}

	template <typename Type>
	std::set<Type> CombinationGenerator_noReps<Type>::GenerateNthSubset(unsigned int N) const
	{
		std::vector<bool> BinaryVector = Extras::NumberRepresentation::Codes::uIntToBinaryCode(N, Elements.size());
		return GetSubset(Elements, BinaryVector);
	}

	template <typename Type>
	std::set<Type> CombinationGenerator_noReps<Type>::GenerateNthCombination(unsigned int N, unsigned int K) const
	{
		unsigned int v, left_p, right_p, S = Elements.size();
		typename std::set<Type>::iterator it = Elements.begin();
		std::set<Type> Result;

		if(K > Elements.size())
			throw std::invalid_argument("K is too large");
		if(N >= Extras::Math::NewtonSymbol(Elements.size(), K))
			throw std::invalid_argument("N is too large");

		N++; //To count combination from 1
		while (S > 0)
		{
			v = Extras::Math::NewtonSymbol(S, K); //Current pascal's triangle value
			right_p = (v * (S - K)) / S; 
			if (K < S)
			{
				left_p = v - right_p;
			}
			else
			{
				left_p = 1;
			}
			S--; 
			if (N > left_p) //Go to right parent, element it isn't in combination
			{
				N = N - left_p; 
			}
			else //Go to left parent, element it is in combination
			{
				K--; 
				Result.insert(*it);
			}
			it++;
		}
		return Result;
	}

	template <typename Type>
	std::set<std::set<Type>> CombinationGenerator_noReps<Type>::GenerateAllCombinations(unsigned int K) const
	{
		std::set<std::set<Type>> Result;
		std::vector<std::vector<bool>> BinarySequences;

		if (K > Elements.size())
			throw std::invalid_argument("K is too large");

		BinarySequences = Extras::Codes::ModifiedGrayCode(Elements.size(), K);
		for (std::vector<std::vector<bool>>::iterator it = BinarySequences.begin(); it != BinarySequences.end(); it++)
		{
			std::set<Type> NewCombination = GetSubset(Elements, *it);
			Result.insert(NewCombination);
		}
		
		return Result;
	}

	template <typename Type>
	std::set<Type> CombinationGenerator_noReps<Type>::GenerateRandomCombination(unsigned int K) const
	{
		unsigned int N = rand() % NumberOfAllCombinations(K);
		return GenerateNthCombination(N, K);
	}


}

