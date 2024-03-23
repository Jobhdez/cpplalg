#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "polynomials.cpp"

std::vector<double> coefficients = {3.0,2.0,1.0};
std::vector<double> coefficients2 = {1.0, 1.0, 1.0};
Polynomial poly(coefficients);
Polynomial poly2 = poly + poly;
Polynomial poly3(coefficients2);
Polynomial poly4 = poly - poly3;

std::vector<double> expected_coefficients = {6.0,4.0,2.0};
std::vector<double> expected_coefficients2 = {2.0,1.0,0.0};
TEST_CASE( "Polynomial tests", "[polynomials]" ) {
  REQUIRE(poly2.getCoefficients() == expected_coefficients);
  REQUIRE(poly4.getCoefficients() == expected_coefficients2);
}
