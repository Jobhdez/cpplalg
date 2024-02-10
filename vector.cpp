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

  double operator*(const Vector& other) const {
  
    std::vector<double> v1(elements.size());
    double sum = 0;
    for (size_t i = 0; i < elements.size(); ++i) {
      v1[i] = elements[i] * other.elements[i];
      sum = sum + v1[i];
    }

    return sum;
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

  Vector logarithm() {
    Vector result;
    for (size_t i = 0; i < elements.size(); ++i) {
      result.elements.push_back(log(elements[i]));
    }
    return result;
  }

  Vector mulByScalar(const double scalar) const {
    Vector result;
    for (size_t i = 0; i < elements.size(); i++) {
      result.elements.push_back(elements[i] * scalar);
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
