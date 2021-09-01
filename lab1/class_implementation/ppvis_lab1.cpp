#include <iostream>
#include "natural_fraction.h"

int main()
{
	NaturalFraction fr;
	fr.setNum(13);
	fr.setDen(6);
	printf("%d %d %d", fr.getNum(), fr.getDen(), fr.getIntegerPart());
}
