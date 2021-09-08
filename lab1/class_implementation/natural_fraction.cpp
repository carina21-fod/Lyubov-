#define _CRT_SECURE_NO_WARNINGS

#include "natural_fraction.h"
#include <iostream>

using namespace std;

NaturalFraction::NaturalFraction()
{
	setNumerator(1);
	setDenominator(1);
}
NaturalFraction::NaturalFraction(int num, int den)
{
	setNumerator(num);
	setDenominator(den);
}
NaturalFraction::NaturalFraction(NaturalFraction& currFraction)
{
	numerator = currFraction.numerator;
	denominator = currFraction.denominator;
}

int NaturalFraction::getNumerator() { return numerator; }
int NaturalFraction::getDenominator() { return denominator; }
void NaturalFraction::setNumerator(int newNum) 
{ 
	numerator = newNum; 
	numeratorSet = true;
	reduce();
}
void NaturalFraction::setDenominator(int newDen) 
{ 
	denominator = newDen; 
	denominatorSet = true;
	reduce();
}
int NaturalFraction::getIntegerPart() { return numerator / denominator; }
void NaturalFraction::reduce() 
{ 
	if (!numeratorSet || !denominatorSet) return;
	int less = (numerator < denominator) ? numerator : denominator;
	for (int currdivisor = 2; currdivisor <= less; currdivisor++)
	{
		if (numerator % currdivisor == 0 && denominator % currdivisor == 0)
		{
			numerator /= currdivisor;
			denominator /= currdivisor;
			currdivisor--;
		}
	}
}
double NaturalFraction::toDouble()
{
	double numeratorDouble = numerator * 1.0;
	return numeratorDouble / denominator;
}

NaturalFraction NaturalFraction::operator+(const NaturalFraction& term)
{
	NaturalFraction result;
	result.setDenominator(term.denominator * denominator);
	result.setNumerator(numerator * term.denominator + term.numerator * denominator);
	return result;
}
NaturalFraction NaturalFraction::operator+(int term)
{
	NaturalFraction result;
	result.setDenominator(denominator);
	result.setNumerator(numerator + term * denominator);
	return result;
}
NaturalFraction NaturalFraction::operator-(int term)
{
	NaturalFraction result;
	result.setDenominator(denominator);
	result.setNumerator(numerator - term * denominator);
	return result;
}
NaturalFraction NaturalFraction::operator/(int term)
{
	NaturalFraction result;
	result.setNumerator(numerator);
	result.setDenominator(denominator * term);
	return result;
}

void NaturalFraction::operator+=(const NaturalFraction& term)
{
	int tempdenominator = denominator;
	denominator = term.denominator * denominator;
	numerator = numerator * term.denominator + term.numerator * tempdenominator;
	reduce();
}
void NaturalFraction::operator+=(int term)
{
	setNumerator(numerator + term * denominator);
}
void NaturalFraction::operator-=(int term)
{
	setNumerator(numerator - term * denominator);
}
void NaturalFraction::operator/=(int term)
{
	denominator *= term;
}

bool NaturalFraction::operator==(const NaturalFraction& term)
{
	if (numerator == term.numerator && denominator == term.denominator) return true;
	else return false;
}
bool NaturalFraction::operator!=(const NaturalFraction& term)
{
	if (numerator != term.numerator || denominator != term.denominator) return true;
	else return false;
}

istream& operator>>(istream& input, NaturalFraction& fr)
{
	input >> fr.numerator >> fr.denominator;
	fr.reduce();
	return input;
}
ostream& operator<<(ostream& output, NaturalFraction& fr)
{
	output << fr.numerator << "/" << fr.denominator;
	return output;
}

void tests()
{
	int testsPassed = 0;

	printf("\n----taking the numerator and the denominator----\n\n");
	printTestResult(test1(), &testsPassed);
	printTestResult(test2(), &testsPassed);

	printf("\n----taking the integer part----\n\n");
	printTestResult(test3_5(new NaturalFraction(3,5), 0), &testsPassed);
	printTestResult(test3_5(new NaturalFraction(13,6), 2), &testsPassed);
	printTestResult(test3_5(new NaturalFraction(73,15), 4), &testsPassed);

	printf("\n----reducing a fraction----\n\n");
	printTestResult(test6_10(new NaturalFraction(6,8), 3, 4), &testsPassed);
	printTestResult(test6_10(new NaturalFraction(30,15), 2, 1), &testsPassed);
	printTestResult(test6_10(new NaturalFraction(8,40), 1, 5), &testsPassed);
	printTestResult(test6_10(new NaturalFraction(100,1), 100, 1), &testsPassed);
	printTestResult(test6_10(new NaturalFraction(10395,46080), 231, 1024), &testsPassed);

	printf("\n----converting a fraction to double----\n\n");
	printTestResult(test11_15(new NaturalFraction(1,2), 1/2.0), &testsPassed);
	printTestResult(test11_15(new NaturalFraction(4,5), 4/5.0), &testsPassed);
	printTestResult(test11_15(new NaturalFraction(18,7), 18/7.0), &testsPassed);
	printTestResult(test11_15(new NaturalFraction(1563,124), 1563/124.0), &testsPassed);
	printTestResult(test11_15(new NaturalFraction(52137,389257), 52137/389257.0), &testsPassed);

	printf("\n----copying a fraction----\n\n");
	printTestResult(test16_20(new NaturalFraction(3,5), 3, 5), &testsPassed);
	printTestResult(test16_20(new NaturalFraction(5,8), 5, 8), &testsPassed);
	printTestResult(test16_20(new NaturalFraction(15,7), 15, 7), &testsPassed);
	printTestResult(test16_20(new NaturalFraction(346,21), 346, 21), &testsPassed);
	printTestResult(test16_20(new NaturalFraction(1,2351), 1, 2351), &testsPassed);

	printf("\n----checking if two fractions are equal----\n\n");
	printTestResult(test21_24(new NaturalFraction(2,3), new NaturalFraction(2,3), true), &testsPassed);
	printTestResult(test21_24(new NaturalFraction(10,13), new NaturalFraction(11,13), false), &testsPassed);
	printTestResult(test21_24(new NaturalFraction(101,21), new NaturalFraction(101,21), true), &testsPassed);
	printTestResult(test21_24(new NaturalFraction(461309,12498), new NaturalFraction(461309,12499), false), &testsPassed);
}

void printTestResult(bool result, int* counter)
{
	if (result)
	{
		printf("test passed\n");
		(*counter)++;
	}
	else printf("TEST FAILED\n");
}

bool test1()
{
	NaturalFraction fr(3, 5);
	printf("Expected: 3, Got: %d; ", fr.getNumerator());
	if (fr.getNumerator() == 3) return true;
	else return false;
}
bool test2()
{
	NaturalFraction fr(5, 8);
	printf("Expected: 8, Got: %d; ", fr.getDenominator());
	if (fr.getDenominator() == 8) return true;
	else return false;
}
bool test3_5(NaturalFraction* fr, int expected)
{
	printf("Expected: %d, Got: %d; ", expected, fr->getIntegerPart());
	if (fr->getIntegerPart() == expected) return true;
	else return false;
}
bool test6_10(NaturalFraction* fr, int expectedNum, int expectedDen)
{
	printf("Expected: %d/%d, Got: %d/%d; ", expectedNum, expectedDen, fr->getNumerator(), fr->getDenominator());
	if (fr->getNumerator() == expectedNum && fr->getDenominator() == expectedDen) return true;
	else return false;
}
bool test11_15(NaturalFraction* fr, double expected)
{
	printf("Expected: %lf, Got: %lf; ", expected, fr->toDouble());
	if (expected == fr->toDouble()) return true;
	else return false;
}
bool test16_20(NaturalFraction* fr, int expectedNum, int expectedDen)
{
	NaturalFraction result = *fr;
	printf("Expected: %d/%d, Got: %d/%d; ", fr->getNumerator(), fr->getDenominator(), result.getNumerator(), result.getDenominator());
	if (result.getNumerator() == expectedNum && result.getDenominator() == expectedDen) return true;
	else return false;
}
bool test21_24(NaturalFraction* fr1, NaturalFraction* fr2, bool expected)
{
	char* expect, * got;
	if (expected)
	{
		expect = new char[5];
		strcpy(expect, "true");
	}
	else
	{
		expect = new char[6];
		strcpy(expect, "false");
	}
	if (*fr1 == *fr2)
	{
		got = new char[5];
		strcpy(got, "true");
	}
	else
	{
		got = new char[6];
		strcpy(got, "false");
	}
	printf("Expected: %s, Got: %s; ", expect, got);
	if ((*fr1 == *fr2) == expected) return true;
	else return false;
}