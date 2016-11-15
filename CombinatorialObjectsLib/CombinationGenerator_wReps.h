#pragma once
#include <set>

namespace CombinatorialObjectsLib
{
	template <typename Type = int>
	class CombinationGenerator_wReps
	{
	private:
		std::set<Type> Elements;

	public:
		CombinationGenerator_wReps() {}
		CombinationGenerator_wReps(std::set<Type> _Elements) : Elements(_Elements) {}
		~CombinationGenerator_wReps() {}
		size_t NumberOfAllSubsets() const;
		size_t NumberOfAllCombinations(unsigned int K) const;
		std::multiset<Type> GenerateNthSubset(unsigned int N) const;
		std::multiset<Type> GenerateNthCombination(unsigned int N, unsigned int K) const;
		std::multiset<std::set<Type>> GenerateAllSubsets() const;
		std::set<std::multiset<Type>> GenerateAllCombinations(unsigned int K) const;
		std::multiset<Type> GenerateRandomSubset() const;
		std::multiset<Type> GenerateRandomCombination(unsigned int K) const;


	};
}
