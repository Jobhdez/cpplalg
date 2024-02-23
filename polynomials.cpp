#include <iostream>
#include <vector>

class Polynomial {
private:
  std::vector<double> coefficients;
public:
  Polynomial() {}

  Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {}

  Polynomial(const Polynomial& other) : coefficients(other.coefficients) {}

  ~Polynomial() {}

  void print_poly() {
    int exponent = coefficients.size() - 1;
    std::cout << "+"  << std::endl;
    for (size_t i = 0; i<coefficients.size(); i++) {
      std::cout << coefficients[i] << "x^" << exponent << " " << std::endl;
      exponent -= 1;
    }
  }

  Polynomial operator+(const Polynomial& other) const {
    Polynomial poly(coefficients);
    for (size_t i = 0; i < coefficients.size(); i++) {
      poly.coefficients[i] = coefficients[i] + other.coefficients[i];
    }
    return poly;
  }
  Polynomial operator-(const Polynomial& other) const {
    Polynomial poly(coefficients);
    for (size_t i = 0; i < coefficients.size(); i++) {
      poly.coefficients[i] = coefficients[i] - other.coefficients[i];
    }
    return poly;
  }

  Polynomial operator*(const Polynomial& other) const {
    double degreep1 = coefficients.size();
    double degreep2 = other.coefficients.size();
    Polynomial result(std::vector<double>(degreep1 + degreep2 - 1));
    for (size_t i = 0; i < degreep1; i++) {
      for (size_t j = 0; j < degreep2; j++) {
	result.coefficients[i+j] += coefficients[i] * other.coefficients[j];
	  }
    }
    return result;
  }
};
/*
int main() {
  std::vector<double> coeffs = {3.0, 2.0, 4.0};
  Polynomial poly(coeffs);
  Polynomial poly2 = poly * poly;
  poly2.print_poly();
}
*/
