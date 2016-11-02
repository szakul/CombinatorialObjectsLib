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
	system("pause");
    return 0;
}

