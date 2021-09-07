#include <iostream>

using namespace std;

class NaturalFraction
{
private:
	int numerator, denominator;
	bool numeratorSet, denominatorSet;
	void reduce();
public:
	int getNumerator();
	int getDenominator();
	void setNumerator(int newNum);
	void setDenominator(int newDen);
	int getIntegerPart();
	double toDouble();

	NaturalFraction operator+(const NaturalFraction& term);
	NaturalFraction operator+(int term);
	NaturalFraction operator-(int term);
	NaturalFraction operator/(int term);

	void operator+=(const NaturalFraction& term);
	void operator+=(int term);
	void operator-=(int term);
	void operator/=(int term);

	bool operator==(const NaturalFraction& term);
	bool operator!=(const NaturalFraction& term);

	friend istream& operator>>(istream& input, NaturalFraction& fr);
	friend ostream& operator<<(ostream& input, NaturalFraction& fr);
};

void tests();

bool test1(); // testing the ability to take the numerator of a fraction
bool test2(); // testing the ability to take the denominator of a fraction
bool test3(); // tests 3-5: testing the ability to take the integer part of a fraction
bool test4();
bool test5();
bool test6(); // tests 6-10: testing the ability to reduce a fraction
bool test7();
bool test8();
bool test9();
bool test10();
bool test11(); // tests 11-15: testing the 
bool test12();
bool test13();
bool test14();
bool test15();