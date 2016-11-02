#pragma once
#include "NaturalNumberRepresentation.h"

namespace CombinatorialObjects
{
	namespace Extras
	{
		namespace NumberRepresentation
		{
			template <unsigned long Base = 10>
			class PositionalNumeralSystem : public NumeralSystem
			{
			public:
				PositionalNumeralSystem() {}
				virtual std::vector<unsigned int> getRepresentation(unsigned long N);
				virtual unsigned long getWeight(unsigned int i);
				unsigned int maxAllowedDigit(unsigned int i) { return Base - 1; }

			};

			//SPECIALIZATIONS TYPEDEFS

			typedef PositionalNumeralSystem<2> BinaryNumeralSystem;

			//SPECIALIZATIONS FOR INVALID BASE

			template <>
			class PositionalNumeralSystem<1> : public NumeralSystem
			{
			public:
				PositionalNumeralSystem() {}
				virtual std::vector<unsigned int> getRepresentation(unsigned long N) { return std::vector<unsigned int>(); }
				virtual unsigned long getWeight(unsigned int i) { return 1; }
				unsigned int maxAllowedDigit(unsigned int i) { return 0; }

			};

			template <>
			class PositionalNumeralSystem<0> : public NumeralSystem
			{
			public:
				PositionalNumeralSystem() {}
				virtual std::vector<unsigned int> getRepresentation(unsigned long N) { return std::vector<unsigned int>(); }
				virtual unsigned long getWeight(unsigned int i) { return 0; }
				unsigned int maxAllowedDigit(unsigned int i) { return 0; }

			};

			//FUNCTION MEMBERS DEFINITIONS

			template <unsigned long Base>
			std::vector<unsigned int> PositionalNumeralSystem<Base>::getRepresentation(unsigned long N)
			{
				std::vector<unsigned int> rep;
				while (N > 0)
				{
					rep.push_back(N % Base);
					N /= Base;
				}
				return rep;
			}

			template <unsigned long Base>
			unsigned long PositionalNumeralSystem<Base>::getWeight(unsigned int i)
			{
				return pow(Base, i);
			}
		}
	}
}
