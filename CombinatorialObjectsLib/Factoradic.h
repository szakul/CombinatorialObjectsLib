#pragma once
#include "NumeralSystem.h"

namespace CombinatorialObjects
{
	namespace Extras
	{
		namespace NumberRepresentation
		{
			class Factoradic : public NumeralSystem
			{
			public:
				virtual std::vector<unsigned int> getRepresentation(unsigned long N);
				virtual unsigned long getWeight(unsigned int i);
				virtual unsigned int maxAllowedDigit(unsigned int i);
			};
		}
	}
}


