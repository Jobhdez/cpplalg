#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fraction.cpp"

Fraction f1(2,3);
Fraction f2 = f1 + f1;
Fraction f3 = f1 * f1;
Fraction f4 = f1/f1;
TEST_CASE( "fractions", "[fractions]") {
  REQUIRE(f2.getNumerator() == 12);
  REQUIRE(f2.getDenominator() == 9);
  REQUIRE(f3.getNumerator() == 4);
  REQUIRE(f3.getDenominator() == 9);
  REQUIRE(f4.getNumerator() == 6);
  REQUIRE(f4.getDenominator() == 6);
}
  
	  
