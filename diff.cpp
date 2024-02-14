#include <iostream>
#include <memory>

class Diff {
public:
    virtual int derivative() const = 0;
};

class DiffVar : public Diff {
private:
    char var;
public:
    DiffVar() {}
    DiffVar(const char& e) : var(e) {}
    int derivative() const override {
        return 1;
    }
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
};

class DiffSum : public Diff {
private:
    std::shared_ptr<Diff> lhs;
    std::shared_ptr<Diff> rhs;
public:
    DiffSum(std::shared_ptr<Diff> left, std::shared_ptr<Diff> right) : lhs(left), rhs(right) {}
    int derivative() const override {
        return lhs->derivative() + rhs->derivative();
    }
};

int main() {
    // Example usage
    std::shared_ptr<Diff> diff1 = std::make_shared<DiffVar>('x');
    std::shared_ptr<Diff> diff2 = std::make_shared<DiffNum>(5);
    DiffSum sum(diff1, diff2);

    int result = sum.derivative();
    std::cout << "Result for DiffSum: " << result << std::endl;

    return 0;
}
