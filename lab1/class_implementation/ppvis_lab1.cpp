#include <iostream>
#include "natural_fraction.h"

int main()
{
	NaturalFraction fr;
	fr.setNumerator(42);
	fr.setDenominator(6);
	printf("%d %d %d", fr.getNumerator(), fr.getDenominator(), fr.getIntegerPart());
}
