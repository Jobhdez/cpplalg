#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.cpp"

std::vector<double> v1_elements = {1.0, 2.0, 3.0};
std::vector<double> v2_elements = {4.0, 5.0, 6.0};
Vector v1(v1_elements);
Vector v2(v2_elements);
Vector v3 = v1 + v2;
Vector v4 = v2 - v1;
double d1 = v1 * v2;
Vector by_scalar = v1.mulByScalar(3.0);
Vector by_log = v1.logarithm();
Vector by_exp = v1.exponent();
Vector by_pow =  v1.power(3.0);
std::vector<double> expected_elements = {5.0, 7.0, 9.0};
std::vector<double> expected_elements_2 = {3.0, 3.0, 3.0};
std::vector<double> expected_exponent_wise = {2.7182818285, 7.3890560989, 20.0855369232};
std::vector<double> expected_power_wise = {1.0, 8.0, 27.0};
std::vector<double> expected_scalar_wise = {3.0, 6.0, 9.0};
//std::vector<double> expected_log_wise = {0, 0.693147, 1.09869};
TEST_CASE( "Vector algebra", "[vectors]" ) {
  REQUIRE(v3.getElements() ==  expected_elements);
  REQUIRE(v4.getElements() == expected_elements_2);
  REQUIRE(v1*v2 == 32.0);
  REQUIRE(by_pow.getElements() == expected_power_wise);
  REQUIRE(by_scalar.getElements() == expected_scalar_wise);
  REQUIRE(by_exp.getElements() == expected_exponent_wise);
  //REQUIRE(by_log.getElements() = expected_log_wise);
}
