#include "Factoradic.h"
#include "MathFormulas.h"

using namespace CombinatorialObjectsLib::Extras::NumberRepresentation;

std::vector<unsigned int> Factoradic::getRepresentation(unsigned long N)
{
	std::vector<unsigned int> Representation;

	unsigned int i = 1;
	while (N > 0)
	{
		Representation.push_back(N % i);
		N /= i++;
	}
	return Representation;
}

unsigned long Factoradic::getWeight(unsigned int i)
{
	return Math::Factorial(i);
}


unsigned int Factoradic::maxAllowedDigit(unsigned int i)
{
	return i;
}