// CombinatorialObjectsExe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CombinatorialObjectsLib.h"
#include <set>
#include <string>

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



int main()
{
	/*
	std::set<char> Elements = { 'A', 'B', 'C', 'D', 'E', '1', '2', '3', '4' };
	VariationGenerator_wReps<char> _Generator(Elements);
	std::vector<char> VEC = _Generator.GenerateNthVariation(0, 10);

	for (int i = 0; i < _Generator.NumberOfAllVariations(10); i++)
	{
		show(_Generator.GenerateNthVariation(i, 10));	
	}
	

	PositionalNumeralSystem<2> A;
	show(A.getRepresentation(300));
	NaturalNumberRepresentation a(300, 3, new PositionalNumeralSystem<10>());
	a.operator--();

	BinaryNumeralSystem E;
	show(E.getRepresentation(300));
	NaturalNumberRepresentation b(6);
	b.operator--();
	*/





	


	
	//show(_Generator.GenerateAllPermutations());
	system("pause");
    return 0;
}

