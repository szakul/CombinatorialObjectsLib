#include "MathFormulas.h"
#include <iostream>

using namespace CombinatorialObjectsLib::Extras;

unsigned int Math::NewtonSymbol(unsigned int N, unsigned int K)
{
	if (K > N)
		throw std::invalid_argument("K is greather than N");
	return ((K == 0) || (N == K)) ? 1 : NewtonSymbol(N - 1, K - 1) + NewtonSymbol(N - 1, K);
}

unsigned long long Math::Factorial(unsigned int N)
{
	return (N == 1 || N == 0) ? 1 : Factorial(N - 1)*N;
}