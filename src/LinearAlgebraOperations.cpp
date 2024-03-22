#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;
namespace LinearAlgebra {
namespace Matrix {

template <typename T>
vector<vector<T>> add(const vector<vector<T>> &matrix1,
                      const vector<vector<T>> &matrix2) {
  assert(matrix1.size() == matrix2.size());
  assert(matrix1[0].size() == matrix2[0].size());
  vector<vector<T>> result_matrix(matrix1.size(), vector<T>(matrix1[0].size()));

  for (size_t i = 0; i < matrix1.size(); i++) {
    for (size_t j = 0; j < matrix1[0].size(); j++) {
      result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  return result_matrix;
}
template <typename T>
vector<vector<T>> sub(const vector<vector<T>> &matrix1,
                      const vector<vector<T>> &matrix2) {
  assert(matrix1.size() == matrix2.size());
  assert(matrix1[0].size() == matrix2[0].size());
  vector<vector<T>> result_matrix(matrix1.size(), vector<T>(matrix1[0].size()));

  for (size_t i = 0; i < matrix1.size(); i++) {
    for (size_t j = 0; j < matrix1[0].size(); j++) {
      result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }

  return result_matrix;
}
template <typename T>
vector<vector<T>> mul(const vector<vector<T>> &matrix1,
                      const vector<vector<T>> &matrix2) {
  assert(matrix1[0].size() == matrix2.size());
  vector<vector<T>> result_matrix(matrix1.size(), vector<T>(matrix2[0].size()));

  for (size_t i = 0; i < matrix1.size(); i++) {
    for (size_t j = 0; j < matrix2[0].size(); j++) {
      result_matrix[i][j] = 0.0;
      for (size_t k = 0; k < matrix1[0].size(); k++) {
        result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result_matrix;
}

  template<typename T>
  void print(const vector<vector<T>>& elements) {
    for (size_t i = 0; i < elements.size(); i++) {
      for (size_t j = 0; j < elements[0].size(); j++)
	std::cout << elements[i][j] << " ";
    
      std::cout << std::endl;
    }
  }
}
  namespace Vec {

    template<typename T>
    vector<T> add(const vector<T>& vec1, const vector<T>& vec2) {
    assert(vec1.size() == vec2.size());
    vector<T> result_vec(vec1.size());

    for (size_t j = 0; j < vec1.size(); j++) {
	result_vec[j] = vec1[j] + vec2[j];
      }

    return result_vec;
  }

    template<typename T>
    vector<T> sub(const vector<T>& vec1, const vector<T>& vec2) {
    assert(vec1.size() == vec2.size());
    vector<T> result_vec(vec1.size());

    for (size_t j = 0; j < vec1.size(); j++) {
	result_vec[j] = vec1[j] - vec2[j];
      }

    return result_vec;
  }
    template<typename T>
    T mul(const vector<T>& vec1, const vector<T>& vec2) {
      assert(vec1.size() == vec2.size());
      vector<T> result_vec(vec1.size());

      T sum = 0;
      for (size_t i = 0; i < vec1.size(); ++i) {
	result_vec[i] = vec1[i] * vec2[i];
         sum = sum + result_vec[i];
    }

      return sum;
    }

  template<typename T>
  void print(const vector<T>& elements) {
    for (size_t i = 0; i < elements.size(); i++) {
      std::cout << elements[i] << " ";
    }
  }
      
 }
}

int main() {

  vector<vector<double>> mat = {{3.0,4.0,5.0}, {3.0,4.0,5.0}};
  vector<double> mat2 = {3.0,4.0,5.0};
  using namespace LinearAlgebra;

  vector<vector<double>> res = Matrix::add(mat, mat);
  Matrix::print(res);
  vector<double> res2 = Vec::add(mat2, mat2);
  Vec::print(res2);
}
