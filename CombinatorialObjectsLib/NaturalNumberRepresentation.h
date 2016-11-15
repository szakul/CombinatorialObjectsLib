#pragma once
#include "NumeralSystem.h"

namespace CombinatorialObjectsLib
{
	namespace Extras
	{
		namespace NumberRepresentation
		{
			const unsigned int DECIMAL = 10;

			class NaturalNumberRepresentation
			{
			private:
				NumeralSystem* _NumeralSystem;
				std::vector<unsigned int> Content;
				unsigned long Value;

				void computeRepresentation();
			public:
				NaturalNumberRepresentation(unsigned long value, size_t min_length, NumeralSystem* numeralSystem);
				NaturalNumberRepresentation(unsigned long value);
				~NaturalNumberRepresentation();
				void changeNumeralSystem(NumeralSystem*);
				size_t length();
				unsigned int getSumOfDigits();
				unsigned int operator[](unsigned int);
				NaturalNumberRepresentation& operator++ ();
				NaturalNumberRepresentation& operator-- ();
			};
		}
	}

}