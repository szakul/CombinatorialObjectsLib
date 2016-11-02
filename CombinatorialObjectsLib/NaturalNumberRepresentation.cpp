#include "NaturalNumberRepresentation.h"
#include "PositionalNumeralSystem.h"

using namespace CombinatorialObjects::Extras::NumberRepresentation;

NaturalNumberRepresentation::NaturalNumberRepresentation(unsigned long value, size_t min_length, NumeralSystem* numeralSystem)
{
	Value = value;
	_NumeralSystem = numeralSystem;
	computeRepresentation();
	if(min_length > Content.size())
		Content.resize(min_length);
}

NaturalNumberRepresentation::NaturalNumberRepresentation(unsigned long value)
{
	Value = value;
	_NumeralSystem = new PositionalNumeralSystem<DECIMAL>();
	computeRepresentation();
}

NaturalNumberRepresentation::~NaturalNumberRepresentation()
{
	if (_NumeralSystem != nullptr)
		delete _NumeralSystem;
}

void NaturalNumberRepresentation::computeRepresentation()
{
	if (_NumeralSystem != nullptr)
		Content = _NumeralSystem->getRepresentation(Value);
}

void NaturalNumberRepresentation::changeNumeralSystem(NumeralSystem* newNumeralSystem)
{
	if (_NumeralSystem != nullptr)
	{
		delete _NumeralSystem;
		_NumeralSystem = newNumeralSystem;
	}
		
}

size_t NaturalNumberRepresentation::length()
{
	return Content.size();
}

unsigned int NaturalNumberRepresentation::operator[](unsigned int i)
{
	return Content[i];
}

NaturalNumberRepresentation& NaturalNumberRepresentation::operator++ ()
{
	unsigned int i = 0;

	while (i < Content.size() && Content[i] == _NumeralSystem->maxAllowedDigit(i))
	{
		Content[i++] = 0;
	}
	Content[i]++; 
	Value++;
	return *this;
}

NaturalNumberRepresentation& NaturalNumberRepresentation::operator-- ()
{
	unsigned int i = 0;
	unsigned int lowestAllowedDigit = 0;

	while (i < Content.size() && Content[i] == lowestAllowedDigit)
	{
		Content[i++] = _NumeralSystem->maxAllowedDigit(i);
	}
	Content[i]--;
	Value--;
	return *this;
}

unsigned int NaturalNumberRepresentation::getSumOfDigits()
{
	unsigned int sum = 0;

	for (auto digit : Content)
	{
		sum += digit;
	}
	return sum;
}



