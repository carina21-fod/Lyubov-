#include "natural_fraction.h"
#include <iostream>

using namespace std;

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
void NaturalFraction::print()
{
if (denominator == 1)  cout << numerator << endl; 
else cout << numerator << "/" << denominator << endl; 
}
void NaturalFraction::reduce() 
{ 
	if (!numeratorSet || !denominatorSet) return;
	int less = (numerator < denominator) ? numerator : denominator;
	for (int currdivisor = 1; currdivisor <= less; currdivisor++)
	{
		if (numerator % currdivisor == 0 && denominator % currdivisor == 0)
		{
			numerator /= currdivisor;
			denominator /= currdivisor;
		}
	}
}
void NaturalFraction:: operator+(const NaturalFraction& term)
{
	NaturalFraction result;
	if (denominator == term.denominator)
	{
		result.setDenominator(term.denominator);                 //Случай, когда знаменатели равны - просто складываем числители (Можно убрать, будет работать корректно и с одним фрагментом из else)
		result.setNumerator(term.numerator + numerator);
	}
	else
	{
		result.setDenominator(term.denominator * denominator);                                 //Случай, когда знаменатели разные - приводим к общему  
		result.setNumerator(numerator * term.denominator + term.numerator * denominator);
	}     
	result.reduce();
    result.print();
}

void NaturalFraction:: operator+(int term)
{
	if (term == 0) {
		print();
		return;
	}
	NaturalFraction result;
	result.setDenominator(denominator);
	result.setNumerator(numerator + term * denominator);
	result.reduce();
	result.print();
}

void NaturalFraction:: operator+=(const NaturalFraction& term)
{
	if (denominator == term.denominator)
	{
		setNumerator(term.numerator + numerator);        // Случай, когда знаменатели равны - просто складываем числители (Можно убрать, будет работать корректно и с одним фрагментом из else)
	}
	else
	{
		setDenominator(term.denominator * denominator);                               //Случай, когда знаменатели разные - приводим к общему  
		setNumerator(numerator * term.denominator + term.numerator * denominator);
	}
	reduce();
	print();
}

void NaturalFraction:: operator+=(int term)
{
	if (term == 0) {
		print();
		return;
	}
	setNumerator(numerator + term * denominator);
	reduce();
	print();
}

void NaturalFraction:: operator-(int term)
{
	if (term == 0) {
		print();
		return;
	}
	NaturalFraction result;
	result.setDenominator(denominator);
	result.setNumerator(numerator - term * denominator);
	result.reduce();
	result.print();
}

void NaturalFraction:: operator-=(int term)
{
	if (term == 0) {
		print();
		return;
	}
	setNumerator(numerator - term * denominator);
	reduce();
	print();
}