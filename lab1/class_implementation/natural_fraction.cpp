#include "natural_fraction.h"

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
	for (int currdivisor = 1; currdivisor <= less; currdivisor++)
	{
		if (numerator % currdivisor == 0 && denominator % currdivisor == 0)
		{
			numerator /= currdivisor;
			denominator /= currdivisor;
		}
	}
}