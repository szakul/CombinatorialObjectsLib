#include <vector>

namespace CombinatorialObjects
{
	namespace Extras
	{
		namespace NumberRepresentation
		{
			class NumeralSystem
			{
			public:
				NumeralSystem() {}
				virtual std::vector<unsigned int> getRepresentation(unsigned long N) = 0;
				virtual unsigned long getWeight(unsigned int i) = 0;
				virtual unsigned int maxAllowedDigit(unsigned int i) = 0;
			};
		}
	}
}









