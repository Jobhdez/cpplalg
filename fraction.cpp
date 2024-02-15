#include <iostream>

class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction() {}
  Fraction(const int& numer, const int& denom) : numerator(numer), denominator(denom) {}
  Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}
  ~Fraction() {}

  int getDenominator() const {
    return denominator;
  }

  int getNumerator() const {
    return numerator;
  }

  void print_fraction() {
    std::cout << numerator << "/" << denominator << std::endl;
  }

  Fraction operator+(const Fraction& other) const {
    int numer = (numerator * other.denominator) + (other.numerator * denominator);
    int denom = denominator * other.denominator;

    return Fraction(numer, denom);
  }
};

int main() {
  Fraction f1(2,3);

  Fraction f2 = f1 + f1;

  f2.print_fraction();
}
