#pragma once
#include <vector>
#include "Types.h"

namespace CombinatorialObjects
{
	namespace Extras
	{
		namespace NumberRepresentation
		{
			std::vector<unsigned int> NaturalNumbers(unsigned int N);
			std::vector<std::vector<bool>> BinarySequences(unsigned short NumberOfBits);

			class Codes
			{
			private:
				static InversionTable _algorithm_uIntToFactoradic(unsigned int);
				static void _algorithm_ModifiedGrayCode(unsigned int NumberOfBits, unsigned int NumberOfOnes, std::vector<unsigned int> Reverse_points, std::vector<std::vector<bool>>& Result, std::vector<bool> Current_sequence);
				static void Reverse(std::vector<bool>& Sequence, std::vector<unsigned int>& Reverse_points);
			public:
				static std::vector<std::vector<bool>> ModifiedGrayCode(unsigned int NumberOfBits, unsigned int NumberOfOnes);
				static InversionTable uIntToFactoradic(unsigned int, size_t);
				static std::vector<bool> uIntToBinaryCode(unsigned int, size_t);
			};
		}
	}
}
