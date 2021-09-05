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
	void operator+(const NaturalFraction& term);
	void operator+(int term);
	void operator+=(const NaturalFraction& term);
	void operator+=(int term);
	void operator-(int term);
	void operator-=(int term);
	void print();
};