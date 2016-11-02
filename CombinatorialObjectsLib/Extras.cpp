#include "Extras.h"
#include "Types.h"

using namespace CombinatorialObjects::Extras;




unsigned int CombinatorialObjects::Extras::Math::NewtonSymbol(unsigned int N, unsigned int K)
{
	if (K > N)
		throw std::invalid_argument("K is greather than N");
	return ((K == 0) || (N == K)) ? 1 : NewtonSymbol(N - 1, K - 1) + NewtonSymbol(N - 1, K);
}

unsigned long long CombinatorialObjects::Extras::Math::Factorial(unsigned int N)
{
	return (N == 1 || N == 0) ? 1 : Factorial(N - 1)*N;
}


std::vector<unsigned int> CombinatorialObjects::Extras::Codes::_algorithm_uIntToFactoradic(unsigned int N)
{
	std::vector<unsigned int> OutputSequence = { 0 };

	int d = 0;
	unsigned long long q = N;
	int w = 1;
	while (q != 0)
	{
		d = q % (w + 1);
		OutputSequence.push_back(d);
		q = q / (w + 1);
		w++;
	}
	return OutputSequence;
}

std::vector<bool> CombinatorialObjects::Extras::Codes::uIntToBinaryCode(unsigned int N, size_t NumberOfBits)
{
	std::vector<bool> BoolVector;

	for (int i = 1; i <= NumberOfBits; i++)
	{
		if (N % 2 == 0)
			BoolVector.insert(BoolVector.begin(), 0);
		else
			BoolVector.insert(BoolVector.begin(), 1);
		N = N >> 1;
	}
	return BoolVector;
}

CombinatorialObjects::InversionTable CombinatorialObjects::Extras::Codes::uIntToFactoradic(unsigned int N, size_t TableLength)
{
	CombinatorialObjects::InversionTable Numbers = _algorithm_uIntToFactoradic(N);
	Numbers.resize(TableLength, 0);
	return Numbers;
}

void CombinatorialObjects::Extras::Codes::Reverse(std::vector<bool>& Sequence, std::vector<unsigned int>& Reverse_points)
{
	for (std::vector<unsigned int>::reverse_iterator revp_it = Reverse_points.rbegin(); revp_it != Reverse_points.rend(); revp_it++)
	{
		std::vector<bool>::iterator seq_it = Sequence.begin();
		for (int i = 0; i < *revp_it; i++)
		{
			seq_it++;
		}
		std::reverse(seq_it, Sequence.end());
	}
}

void CombinatorialObjects::Extras::Codes::_algorithm_ModifiedGrayCode(unsigned int NumberOfBits, unsigned int NumberOfOnes, std::vector<unsigned int> Reverse_points, std::vector<std::vector<bool>>& Result, std::vector<bool> Current_sequence)
{
	if (NumberOfOnes > NumberOfBits)
		throw std::invalid_argument("Number of ones is greather than number of bits");

	if (NumberOfOnes == 0)
	{
		for (int i = 0; i < NumberOfBits; i++)
			Current_sequence.push_back(false);
		Reverse(Current_sequence, Reverse_points);
		Result.push_back(Current_sequence);
		return;
	} 
	else if (NumberOfBits == NumberOfOnes)
	{
		for (int i = 0; i < NumberOfBits; i++)
			Current_sequence.push_back(true);
		Reverse(Current_sequence, Reverse_points);
		Result.push_back(Current_sequence);
		return;
	} 

	Current_sequence.push_back(false);
	_algorithm_ModifiedGrayCode(NumberOfBits - 1, NumberOfOnes, Reverse_points, Result, Current_sequence);
	
	*(Current_sequence.rbegin()) = true;
	Reverse_points.push_back(Current_sequence.size());
	_algorithm_ModifiedGrayCode(NumberOfBits - 1, NumberOfOnes - 1, Reverse_points, Result, Current_sequence);
	return;
}

std::vector<std::vector<bool>> CombinatorialObjects::Extras::Codes::ModifiedGrayCode(unsigned int NumberOfBits, unsigned int NumberOfOnes)
{
	std::vector<bool> Current_sequence;
	std::vector<unsigned int> Reverse_points;
	std::vector<std::vector<bool>> Result;
	_algorithm_ModifiedGrayCode(NumberOfBits, NumberOfOnes, Reverse_points, Result, Current_sequence);
	return Result;
}


