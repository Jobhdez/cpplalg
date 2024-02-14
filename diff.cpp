#include <iostream>
#include <memory>
#include <string>
#include <tuple>

using namespace std;

class Diff {
public:
    virtual int derivative() const = 0;
    virtual string get_exp() const = 0; 
};

class DiffVar : public Diff {
private:
    string var;
public:
    DiffVar() {}
    DiffVar(const char& e) : var(1, e) {}
    int derivative() const override {
        return 1;
    }
    string get_exp() const override {
        return var;
    }
    ~DiffVar() {}
};

class DiffNum : public Diff {
private:
    int exp;
public:
    DiffNum() {}
    DiffNum(const int& e) : exp(e) {}
    int derivative() const override {
        return 0;
    }
    string get_exp() const override {
      string exp2 = to_string(exp);
      return exp2;
    }
    ~DiffNum() {}
  
};

class DiffSum : public Diff {
private:
    shared_ptr<Diff> lhs;
    shared_ptr<Diff> rhs;
public:
    DiffSum(shared_ptr<Diff> left, shared_ptr<Diff> right) : lhs(left), rhs(right) {}
    int derivative() const override {
        return lhs->derivative() + rhs->derivative();
    }
     string get_exp() const override {
       return lhs->get_exp() + " + " + rhs->get_exp();
     }
};

std::string mul_exp(int e, int e2) {
  int exp = e*e;
  string exp2 = to_string(exp);
  return exp2;
}

std::string mul_exp(string e, int e2) {
  string e3 = to_string(e2);
  string op = "*";
  return e + op + e3;
}

class DiffProduct {
private:
    shared_ptr<Diff> lhs;
    shared_ptr<Diff> rhs;

public:
    DiffProduct(shared_ptr<Diff> left, shared_ptr<Diff> right) : lhs(left), rhs(right) {}

    tuple<string, char, string> derivative()  {
        int derivative1 = lhs->derivative();
        string e1 = mul_exp(rhs->get_exp(), derivative1); // Fixed here
        int derivative2 = rhs->derivative();
        string e2 = mul_exp(lhs->get_exp(), derivative2); // Fixed here
        return make_tuple(e2, '+', e1);
    }
};

int main() {
    // Example usage
    shared_ptr<Diff> diff1 = make_shared<DiffVar>('x');
    shared_ptr<Diff> diff2 = make_shared<DiffNum>(5);
    DiffSum sum(diff1, diff2);
    DiffProduct prod(diff1, diff2);
    int result = sum.derivative();
    auto result2 = prod.derivative();
    cout << "Result for DiffSum: " << result << endl;
    cout << "The initial values of tuples are :";
    cout << get<0>(result2) << " " << get<1>(result2) << " " << get<2>(result2) << endl;
    return 0;
}
