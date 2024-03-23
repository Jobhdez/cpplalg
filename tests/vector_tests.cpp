#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/LinearAlgebraOperations.cpp"

using namespace LinearAlgebra;

std::vector<double> v1 = {1.0, 2.0, 3.0};
std::vector<double> v2 = {4.0, 5.0, 6.0};

std::vector<float> v1f = {1.0, 2.0, 3.0};
std::vector<float> v2f = {4.0, 5.0, 6.0};

std::vector<long double> v1l = {1.0, 2.0, 3.0};
std::vector<long double> v2l = {4.0, 5.0, 6.0};

std::vector<double> expected_elements = {5.0, 7.0, 9.0};
std::vector<double> expected_elements_2 = {3.0, 3.0, 3.0};
double DOT = 32.0;

std::vector<float> expected_elementsf = {5.0, 7.0, 9.0};
std::vector<float> expected_elements_2f = {3.0, 3.0, 3.0};
float DOTF = 32.0;

std::vector<long double> expected_elementsl = {5.0, 7.0, 9.0};
std::vector<long double> expected_elements_2l = {3.0, 3.0, 3.0};
long double DOTL = 32.0;

TEST_CASE( "Vector algebra", "[vectors]" ) {
  REQUIRE(Vec::add(v1,v2) ==  expected_elements);
  REQUIRE(Vec::sub(v2, v1) == expected_elements_2);
  REQUIRE(Vec::mul(v1, v2) == DOT);
  REQUIRE(Vec::add(v1f,v2f) ==  expected_elementsf);
  REQUIRE(Vec::sub(v2f, v1f) == expected_elements_2f);
  REQUIRE(Vec::mul(v1f, v2f) == DOTF);
  REQUIRE(Vec::add(v1l,v2l) ==  expected_elementsl);
  REQUIRE(Vec::sub(v2l, v1l) == expected_elements_2l);
  REQUIRE(Vec::mul(v1l, v2l) == DOTL);

}
