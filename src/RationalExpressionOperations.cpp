#include "PolynomialOperations.cpp"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace RationalExpression {
template <typename T>
vector<vector<T>> add(const vector<vector<T>> &rat1,
                      const vector<vector<T>> &rat2) {
  assert(rat1[0].size() == rat2[0].size()); // numerators need to be equal
  assert(rat1[1].size() == rat2[1].size()); // denominators need to be equal

  vector<T> n1 = Polynomial::mul(rat1[0], rat2[1]);
  vector<T> d1 = Polynomial::mul(rat1[1], rat2[1]);
  vector<T> n2 = Polynomial::mul(rat2[0], rat1[1]);
  vector<T> d2 = Polynomial::mul(rat2[1], rat1[1]);

  vector<T> p1 = Polynomial::add(n1, n2);
  vector<T> p2 = Polynomial::add(d1, d2);

  vector<vector<T>> result = {p1, p2};

  return result;
}
template <typename T>
vector<vector<T>> sub(const vector<vector<T>> &rat1,
                      const vector<vector<T>> &rat2) {
  assert(rat1[0].size() == rat2[0].size()); // numerators need to be equal
  assert(rat1[1].size() == rat2[1].size()); // denominators need to be equal

  vector<T> n1 = Polynomial::mul(rat1[0], rat2[1]);
  vector<T> d1 = Polynomial::mul(rat1[1], rat2[1]);
  vector<T> n2 = Polynomial::mul(rat2[0], rat1[1]);
  vector<T> d2 = Polynomial::mul(rat2[1], rat1[1]);

  vector<T> p1 = Polynomial::sub(n1, n2);
  vector<T> p2 = Polynomial::sub(d1, d2);

  vector<vector<T>> result = {p1, p2};

  return result;
}

template <typename T>
vector<vector<T>> mul(const vector<vector<T>> &rat1,
                      const vector<vector<T>> &rat2) {
  assert(rat1[0].size() == rat2[0].size()); // numerators need to be equal
  assert(rat1[1].size() == rat2[1].size()); // denominators need to be equal

  vector<T> p1 = Polynomial::mul(rat1[0], rat2[0]);
  vector<T> p2 = Polynomial::mul(rat1[1], rat2[1]);

  vector<vector<T>> result = {p1, p2};

  return result;
}

template <typename T> void print(const vector<vector<T>> &rat) {
  Polynomial::print(rat[0]);
  cout << "   "
       << "---------------------\n";
  Polynomial::print(rat[1]);
}
} // namespace RationalExpression

int main() {

  using namespace RationalExpression;

  vector<int> numer = {2, 3, 4, 5};
  vector<int> denom = {4, 5, 6, 7};

  vector<vector<int>> rat = {numer, denom};

  vector<vector<int>> result = RationalExpression::add(rat, rat);
  RationalExpression::print(result);
}
