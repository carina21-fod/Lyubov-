#include "natural_fraction.h"

int NaturalFraction::getNum() { return numerator; }
int NaturalFraction::getDen() { return denominator; }
void NaturalFraction::setNum(int newNum) { numerator = newNum; }
void NaturalFraction::setDen(int newDen) { denominator = newDen; }
int NaturalFraction::getIntegerPart() { return numerator / denominator; }