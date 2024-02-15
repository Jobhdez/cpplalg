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

  Matrix operator*(const Matrix& other) const {
    Matrix result(elements);

    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements.size(); j++) {
	result.elements[i][j] = 0.0;
	for (size_t k = 0; k < elements.size(); k++) {
	  result.elements[i][j] = result.elements[i][j] + elements[i][k] * other.elements[k][j];
	}
      }
    }
    return result;
  }

  Matrix mulByScalar(const double scalar) const {
    Matrix result(elements);
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++) {
	result.elements[i][j] = elements[i][j] * scalar;
      }
    }
    return result;
  }
  
  Matrix power(const double scalar) const {
    Matrix result(elements);
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++) {
	result.elements[i][j] = pow(elements[i][j], scalar);
      }
    }

    return result;
  }

  Matrix exponent() {
    Matrix result(elements);
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++) {
	result.elements[i][j] = exp(elements[i][j]);
      }
    }
    return result;
  }

  Matrix logarithm() {
    Matrix result(elements);
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++) {
	result.elements[i][j] = log(elements[i][j]);
      }
    }
    return result;
  }
  Matrix transpose() {
    Matrix result(std::vector<std::vector<double>>(elements[0].size(), std::vector<double>(elements.size())));

    for (size_t i = 0; i < elements[0].size(); i++) {
      for (size_t j = 0; j < elements.size(); j++) {
	result.elements[i][j] = elements[j][i];
      }
    }
    return result;
  }
  double trace() {
    double sum = 0.0;
    for (size_t i = 0; i < elements.size(); i++) {
      sum += elements[i][i];
    }
    return sum;
  }
};
/*
int main(){
  std::vector<std::vector<double>> elements = {{2,1,5},{2,3,4},{0,1,0}};
  Matrix m1(elements);

  double m2 = m1.trace();
  std::cout << m2 << std::endl;
}
*/
