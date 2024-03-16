#include <iostream>
#include "polynomials.cpp"

class RationalExp {
private:
  Polynomial numerator;
  Polynomial denominator;

public:
  RationalExp() {}
  RationalExp(const RationalExp& other) : numerator(other.numerator), denominator(other.denominator) {}
  RationalExp(const Polynomial& p1, const  Polynomial& p2) : numerator(p1), denominator(p2) {}
  ~RationalExp() {}

  void print_rational_exp() {
    numerator.print_poly();
    std::cout << "/" <<std::endl;
    denominator.print_poly();
  }

  RationalExp operator+(RationalExp& other) const {
    Polynomial numerRat1 = numerator * other.denominator;
    Polynomial denomRat1 = denominator * other.denominator;

    Polynomial numerRat2 = other.numerator * denominator;
    Polynomial denomRat2 = other.denominator * denominator;

    Polynomial sumRat1 = numerRat1 + numerRat2;
    Polynomial sumRat2 = denomRat1 + denomRat2;

    return RationalExp(sumRat1, sumRat2);
  }
  RationalExp operator*(RationalExp& other) const {
    Polynomial p1 = numerator * other.numerator;
    Polynomial p2 = denominator * other.denominator;
    return RationalExp(p1, p2);
  }
  RationalExp operator/(RationalExp& other) const {
    Polynomial p1 = numerator * other.denominator;
    Polynomial p2 = denominator * other.numerator;
    return RationalExp(p1, p2);
  }
};

int main() {
  std::vector<double> el = {2.0, 3.0};
  Polynomial p1(el);

  RationalExp rat1(p1, p1);
  RationalExp r(rat1);
  RationalExp rat2 = rat1 + rat1;
  RationalExp rat3 = rat1 * rat1;
  RationalExp rat4 = rat1 / rat1;
  rat2.print_rational_exp();
  rat3.print_rational_exp();
  rat4.print_rational_exp();

  return 0;
}
