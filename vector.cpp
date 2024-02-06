#include <iostream>
#include <vector>
#include <cmath>

class Vector {
private:
    std::vector<double> elements;

public:

    Vector() {} 

    Vector(const std::vector<double>& elems) : elements(elems) {}

    
    Vector(const Vector& other) : elements(other.elements) {}

    
    ~Vector() {}

    
    std::vector<double> getElements() const {
        return elements;
    }

    
    Vector operator+(const Vector& other) const {
        if (elements.size() != other.elements.size()) {
            std::cerr << "Error: Vectors must be of equal size for addition." << std::endl;
            return *this; 
        }

        Vector result;
        for (size_t i = 0; i < elements.size(); ++i) {
            result.elements.push_back(elements[i] + other.elements[i]);
        }
        return result;
    }
  Vector operator-(const Vector& other) const {
    if (elements.size() != other.elements.size()) {
      std::cerr << "Error: Vectors must be of equal size for subtraction." << std::endl;
      return *this;
    }
    Vector result;
    for (size_t i = 0; i < elements.size(); ++i) {
      result.elements.push_back(elements[i] - other.elements[i]);
    }
    return result;
  }

  Vector power(const double scalar) const {
    Vector result;
    for (size_t i = 0; i < elements.size(); i++) {
      result.elements.push_back(pow(elements[i], scalar));
    }
   return  result;
  }
  Vector exponent() {
    Vector result;
    for (size_t i = 0; i < elements.size(); i++) {
      result.elements.push_back(exp(elements[i]));
    }
    return result;
  }
};

int main() {
    std::vector<double> v1_elements = {1.0, 2.0, 3.0};
    std::vector<double> v2_elements = {4.0, 5.0, 6.0};

    Vector v1(v1_elements);
    Vector v2(v2_elements);

    Vector v3 = v1 + v2;
    Vector v4 = v2 - v1;
    Vector v5 = v1.power(3.0);
    Vector v6 = v1.exponent();

    
    std::vector<double> result_elements = v3.getElements();
    for (double element : result_elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::vector<double> result_elements2 = v4.getElements();
    for (double element : result_elements2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::vector<double> result_elements3 = v5.getElements();
    for (double element : result_elements3) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::vector<double> result_elements4 = v6.getElements();
    for (double element : result_elements4) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
