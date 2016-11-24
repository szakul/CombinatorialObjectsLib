// CombinatorialObjectsExe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <string>
#include <vector>
#include "VariationGenerator_wReps.h"

template <typename Type>
void show(std::vector<Type> A)
{
	for (typename std::vector<Type>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

template <typename Type>
void show(std::vector<std::vector<Type>> A)
{
	for (typename std::vector<std::vector<Type>>::iterator it = A.begin(); it != A.end(); ++it)
		show<Type>(*it);
}

template <typename Type>
void show(std::set<Type> A)
{
	for (typename std::set<Type>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

template <typename Type>
void show(std::set<std::set<Type>> A)
{
	for (typename std::set<std::set<Type>>::iterator it = A.begin(); it != A.end(); ++it)
		show<Type>(*it);
}

int rek(int i)
{
	if (i == 0)
	{
		return -1;
	}

	std::cout << rek(i - 1) << std::endl;
}

//#include "Header.h"

int main()
{
	using namespace CombinatorialObjectsLib;
	//std::set<char> elements = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	//CombinatorialObjectsLib::VariationGenerator_wReps<char> V(elements);
	//show(V.GenerateAllVariations(4));
	//
	//NumeralSystem* a = new Factoradic();
	//NaturalNumberRepresentation A(15, 10, new BinaryNumeralSystem());
	//for (int i = 9; i >= 0; i--)
	//{
	//	std::cout << A[i] << " ";
	//}

	std::set<char> Elements = { 'A', 'B', 'C' };
	std::vector<char> Variation = { 'C', 'C', 'C', 'C' };
	VariationGenerator_wReps<char> Generator(Elements);
	std::set<char>::reverse_iterator it = Elements.rbegin();
	std::cout << *it << std::endl;
	Generator.GenerateNextVariation(Variation, 4);
	system("pause");
    return 0;
}

