#pragma once
#include <vector>
#include <set>


namespace CombinatorialObjectsLib
{
	template <typename Type = int>
	class VariationGenerator_wReps
	{
		private:
			std::set<Type> Elements;
		public:
			VariationGenerator_wReps() {}
			VariationGenerator_wReps(std::set<Type> _Elements) : Elements(_Elements) {}
			~VariationGenerator_wReps() {}
			unsigned long long NumberOfAllVariations(unsigned int K) const { return pow(Elements.size(), K); }
			//size_t NumberOfAllVariations() const;
			//std::vector<Type> GenerateNthVariation(unsigned int N) const;
			std::vector<Type> GenerateNthVariation(unsigned int N, unsigned int K) const;
			//std::vector<Type> GenerateNextVariation(std::vector<Type> PreviousVariation) const;
			std::vector<Type> GenerateNextVariation(std::vector<Type> PreviousVariation, unsigned int K) const;
			//std::vector<std::vector<Type>> GenerateAllVariations() const;
			std::vector<std::vector<Type>> GenerateAllVariations(unsigned int K) const;
			//std::vector<Type> GenerateRandomVariation() const;
			std::vector<Type> GenerateRandomVariation(unsigned int K) const;
	};

	template <typename Type>
	std::vector<std::vector<Type>> VariationGenerator_wReps<Type>::GenerateAllVariations(unsigned int K) const
	{
		std::vector<std::vector<Type>> Result;

		if (K > Elements.size())
			throw std::invalid_argument("K is too large");

	
		for (std::set<char>::iterator it = Elements.begin(); it != Elements.end(); it++) //First iteration
		{
			Result.push_back(std::vector<char>(1, *it));
		}


			for (int i = 1; i < K; i++)
			{
				std::vector<std::vector<Type>> NewSequences;
				for (typename std::vector<std::vector<Type>>::iterator it1 = Result.begin(); it1 != Result.end(); it1++)
				{
					for (std::set<char>::iterator it2 = Elements.begin(); it2 != Elements.end(); it2++)
					{
						std::vector<Type> NewSequence(*it1);
						NewSequence.push_back(*it2);
						NewSequences.push_back(NewSequence);
					}
				}
				Result = NewSequences;
				NewSequences.clear();
			}
		return Result;
	}

	template <typename Type>
	std::vector<Type> VariationGenerator_wReps<Type>::GenerateNthVariation(unsigned int N, unsigned int K) const
	{
		std::vector<Type> Result;
		size_t NumberOfPossibilitiesOnFirstPlace;
		size_t Size = Elements.size();
		typename std::set<Type>::iterator it_element;

		if(N >= NumberOfAllVariations(K))
			throw std::invalid_argument("N is too large");
		//if(K > Size)
		//	throw std::invalid_argument("K is too large");

		if (Size != 0)
		{
			NumberOfPossibilitiesOnFirstPlace = NumberOfAllVariations(K) / Size;
			for (int i = 0; i < K; i++)
			{
				it_element = Elements.begin();
				std::advance(it_element, (N / NumberOfPossibilitiesOnFirstPlace));
				Result.push_back(*it_element);
				N %= NumberOfPossibilitiesOnFirstPlace;
				NumberOfPossibilitiesOnFirstPlace /= Size;
			}
		}
		return Result;
	}

	template <typename Type>
	std::vector<Type> VariationGenerator_wReps<Type>::GenerateNextVariation(std::vector<Type> PreviousVariation, unsigned int K) const
	{
		typename std::set<Type>::reverse_iterator max_element = Elements.rbegin();
		typename std::vector<Type>::reverse_iterator it = PreviousVariation.rbegin();

		while (*it == *max_element)
		{
			*it++ = *Elements.begin();
		}
		if (it != PreviousVariation.rend())
		{
			typename std::set<Type>::iterator it1;
			it1 = Elements.find(*it);
			*it = *++it1;
		}
		return PreviousVariation;

	}

	template <typename Type>
	std::vector<Type> VariationGenerator_wReps<Type>::GenerateRandomVariation(unsigned int K) const
	{
		return GenerateNthVariation(rand() % NumberOfAllVariations(K), K);
	}
}

