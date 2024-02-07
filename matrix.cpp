#include <iostream>
#include <vector>
#include <cmath>

class Matrix {
private:
  std::vector<std::vector<double>> elements;

public:
  Matrix() {}

  Matrix(const std::vector<std::vector<double>>& elems) : elements(elems) {}

  Matrix(const Matrix& other) : elements(other.elements) {}

  ~Matrix() {}
  
  std::vector<std::vector<double>> getElements() const {
    return elements;
  }
  void print_matrix() {
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++)
	std::cout << elements[i][j] << " ";
    
      std::cout << std::endl;
    }
  }
    
  Matrix operator+(const Matrix& other) const {
    Matrix result(elements);
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++) {
	result.elements[i][j] = elements[i][j] + other.elements[i][j];
      }
    }

    return result;
  }

  Matrix operator-(const Matrix& other) const {
    Matrix result(elements);
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++) {
	result.elements[i][j] = elements[i][j] - other.elements[i][j];
      }
    }

    return result;
  }
};

int main() {
  std::vector<std::vector<double>> m1_elements = {{3.0,4.0,5.0}, {2.0, 5.0, 6.0}};

  std::vector<std::vector<double>> m2_elements = {{4.0,5.0, 6.0}, {6.0, 7.0, 8.0}};

  Matrix m1(m1_elements);

  Matrix m2(m2_elements);

  Matrix m3 = m1 + m1;

  Matrix m4 = m2 - m1;

  m3.print_matrix();
  std::cout << std::endl;
  m4.print_matrix();
}
  
