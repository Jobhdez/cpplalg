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
    int exponent = coefficients.size();
    std::cout << "+"  << std::endl;
    for (size_t i = 0; i<coefficients.size(); i++) {
      std::cout << coefficients[i] << "x^" << exponent << " " << std::endl;
      exponent -= 1;
    }
  }

  Polynomial operator+(Polynomial& other) const {
    Polynomial poly(coefficients);
    for (size_t i = 0; i < coefficients.size(); i++) {
      poly.coefficients[i] = coefficients[i] + other.coefficients[i];
    }
    return poly;
  }
    Polynomial operator-(Polynomial& other) const {
    Polynomial poly(coefficients);
    for (size_t i = 0; i < coefficients.size(); i++) {
      poly.coefficients[i] = coefficients[i] - other.coefficients[i];
    }
    return poly;
  }
};

int main() {
  std::vector<double> coeffs = {3.0, 2.0, 4.0};
  Polynomial poly(coeffs);
  Polynomial poly2 = poly + poly;
  poly2.print_poly();
}
  
