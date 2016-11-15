#include "Codes.h"

using namespace CombinatorialObjectsLib::Extras::NumberRepresentation;

std::vector<unsigned int> CombinatorialObjectsLib::Extras::NumberRepresentation::NaturalNumbers(unsigned int N)
{
	std::vector<unsigned int> Sequence;
	for (unsigned int i = 0; i < N; i++)
	{
		Sequence.push_back(i);
	}
	return Sequence;
}

std::vector<std::vector<bool>> CombinatorialObjectsLib::Extras::NumberRepresentation::BinarySequences(unsigned short NumberOfBits)
{
	std::vector<std::vector<bool>> BinarySequences;
	for (int i = 0; i < pow(2, NumberOfBits); i++)
	{
		std::vector<bool> BinarySequence = Codes::uIntToBinaryCode(i, NumberOfBits);
		BinarySequences.push_back(BinarySequence);
	}
	return BinarySequences;
}

std::vector<unsigned int> Codes::_algorithm_uIntToFactoradic(unsigned int N)
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

std::vector<bool> Codes::uIntToBinaryCode(unsigned int N, size_t NumberOfBits)
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

CombinatorialObjectsLib::InversionTable Codes::uIntToFactoradic(unsigned int N, size_t TableLength)
{
	CombinatorialObjectsLib::InversionTable Numbers = _algorithm_uIntToFactoradic(N);
	Numbers.resize(TableLength, 0);
	return Numbers;
}

void Codes::Reverse(std::vector<bool>& Sequence, std::vector<unsigned int>& Reverse_points)
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

void Codes::_algorithm_ModifiedGrayCode(unsigned int NumberOfBits, unsigned int NumberOfOnes, std::vector<unsigned int> Reverse_points, std::vector<std::vector<bool>>& Result, std::vector<bool> Current_sequence)
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

std::vector<std::vector<bool>> Codes::ModifiedGrayCode(unsigned int NumberOfBits, unsigned int NumberOfOnes)
{
	std::vector<bool> Current_sequence;
	std::vector<unsigned int> Reverse_points;
	std::vector<std::vector<bool>> Result;
	_algorithm_ModifiedGrayCode(NumberOfBits, NumberOfOnes, Reverse_points, Result, Current_sequence);
	return Result;
}
