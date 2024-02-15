#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "matrix.cpp"

std::vector<std::vector<double>> m1_elements = {{3.0,4.0}, {2.0, 5.0}};
std::vector<std::vector<double>> m2_elements = {{4.0,5.0}, {6.0, 7.0}};
std::vector<std::vector<double>> elements = {{2,3,4}, {5,6,7}};
Matrix m1(m1_elements);
Matrix m2(m2_elements);

Matrix m3 = m1 + m2;
Matrix m4 = m2 - m1;
Matrix m5 = m2 * m1;
Matrix m6 = m1.mulByScalar(2.0);
Matrix m7 = m1.power(2.0);
Matrix m8(elements);
Matrix m9 = m8.transpose();

std::vector<std::vector<double>> matrix_sum_elements = {{7.0,9.0}, {8.0, 12.0}};
std::vector<std::vector<double>> matrix_sub_elements = {{1.0,1.0}, {4.0, 2.0}};
std::vector<std::vector<double>> matrix_scalar_elements = {{6.0,8.0}, {4.0, 10.0}};
std::vector<std::vector<double>> matrix_pow_elements = {{9.0,16.0}, {4.0, 25.0}};

std::vector<std::vector<double>> matrix_mul_elements = {{22.0,41.0}, {32.0, 59.0}};
std::vector<std::vector<double>> matrix_transpose = {{2,5},{3,6},{4,7}};

TEST_CASE( "Matrix algebra", "[matrices]" ) {
  REQUIRE(m3.getElements() == matrix_sum_elements);
  REQUIRE(m4.getElements() == matrix_sub_elements);
  REQUIRE(m5.getElements() == matrix_mul_elements);
  REQUIRE(m6.getElements() == matrix_scalar_elements);
  REQUIRE(m7.getElements() == matrix_pow_elements);
  REQUIRE(m9.getElements() == matrix_transpose);
}
