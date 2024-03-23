#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/LinearAlgebraOperations.cpp"

using namespace LinearAlgebra;

std::vector<std::vector<double>> m1 = {{3.0,4.0}, {2.0, 5.0}};
std::vector<std::vector<double>> m2 = {{4.0,5.0}, {6.0, 7.0}};

std::vector<std::vector<float>> m1f = {{3.0,4.0}, {2.0, 5.0}};
std::vector<std::vector<float>> m2f  = {{4.0,5.0}, {6.0, 7.0}};

std::vector<std::vector<long double>> m1l = {{3.0,4.0}, {2.0, 5.0}};
std::vector<std::vector<long double>> m2l  = {{4.0,5.0}, {6.0, 7.0}};

std::vector<std::vector<double>> matrix_sum_elements = {{7.0,9.0}, {8.0, 12.0}};
std::vector<std::vector<double>> matrix_sub_elements = {{1.0,1.0}, {4.0, 2.0}};
std::vector<std::vector<double>> matrix_mul_elements = {{22.0,41.0}, {32.0, 59.0}};

std::vector<std::vector<float>> matrix_sum_elementsf = {{7.0,9.0}, {8.0, 12.0}};
std::vector<std::vector<float>> matrix_sub_elementsf = {{1.0,1.0}, {4.0, 2.0}};
std::vector<std::vector<float>> matrix_mul_elementsf = {{22.0,41.0}, {32.0, 59.0}};

std::vector<std::vector<long double>> matrix_sum_elementsl = {{7.0,9.0}, {8.0, 12.0}};
std::vector<std::vector<long double>> matrix_sub_elementsl = {{1.0,1.0}, {4.0, 2.0}};
std::vector<std::vector<long double>> matrix_mul_elementsl = {{22.0,41.0}, {32.0, 59.0}};

TEST_CASE( "Matrix algebra", "[matrices]" ) {
  REQUIRE(Matrix::add(m1, m2) == matrix_sum_elements);
  REQUIRE(Matrix::sub(m2, m1) == matrix_sub_elements);
  REQUIRE(Matrix::mul(m2, m1) == matrix_mul_elements);
  REQUIRE(Matrix::add(m1f, m2f) == matrix_sum_elementsf);
  REQUIRE(Matrix::sub(m2f, m1f) == matrix_sub_elementsf);
  REQUIRE(Matrix::mul(m2f, m1f) == matrix_mul_elementsf);
  REQUIRE(Matrix::add(m1l, m2l) == matrix_sum_elementsl);
  REQUIRE(Matrix::sub(m2l, m1l) == matrix_sub_elementsl);
  REQUIRE(Matrix::mul(m2l, m1l) == matrix_mul_elementsl);
}
