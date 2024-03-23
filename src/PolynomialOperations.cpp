#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
namespace Polynomial {

template <typename T>
vector<T> add(const vector<T> &poly1, const vector<T> &poly2) {
  assert(poly1.size() == poly2.size());
  vector<T> result_poly(poly1.size());

  for (size_t j = 0; j < poly1.size(); j++) {
    result_poly[j] = poly1[j] + poly2[j];
  }

  return result_poly;
}

template <typename T>
vector<T> sub(const vector<T> &poly1, const vector<T> &poly2) {
  assert(poly1.size() == poly2.size());
  vector<T> result_poly(poly1.size());

  for (size_t j = 0; j < poly1.size(); j++) {
    result_poly[j] = poly1[j] - poly2[j];
  }

  return result_poly;
}
template <typename T>
vector<T> mul(const vector<T> &poly1, const vector<T> &poly2) {
  size_t degreep1 = poly1.size();
  size_t degreep2 = poly2.size();
  vector<T> result_poly(degreep1 + degreep2 - 1, 0);

  for (size_t i = 0; i < degreep1; i++) {
    for (size_t j = 0; j < degreep2; j++) {
      result_poly[i + j] += poly1[i] * poly2[j];
    }
  }
  return result_poly;
}

template <typename T> void print(const vector<T> &coefficients) {
  int degree = coefficients.size() - 1;

  for (int i = degree; i >= 0; --i) {
    if (coefficients[i] != 0) {
      if (i != degree) {
        std::cout << (coefficients[i] > 0 ? " + " : " - ");
      }
      if (i != 0 && std::abs(coefficients[i]) != 1) {
        std::cout << std::abs(coefficients[i]);
      } else if (i == 0 || std::abs(coefficients[i]) != 1) {
        std::cout << std::abs(coefficients[i]);
      }

      if (i > 0) {
        std::cout << "x";
        if (i > 1) {
          std::cout << "^" << i;
        }
      }
    }
  }

  std::cout << std::endl;
}

} // namespace Polynomial
/*
int main() {
  using namespace Polynomial;
  std::vector<int> p = {5, 4, 2, 5};
  std::vector<int> p2 = add(p, p);
  std::vector<int> p3 = mul(p, p);
  print(p2);
  cout << "\n";
  print(p3);
  }*/
