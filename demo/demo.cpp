#include <iostream>
#include <stdexcept>

class Calculator {
public:
    // Constructor
    Calculator() = default;

    // Destructor
    ~Calculator() = default;

    // Addition
    double add(double var1, double var2) const {
        return var1 + var2;
    }

    // Subtraction
    double subtract(double var1, double var2) const {
        return var1 - var2;
    }

    // Multiplication
    double multiply(double var1, double var2) const {
        return var1 * var2;
    }

    // Division
    double divide(double var1, double var2) const {
	double result = var1 / var2;
        return result;
    }
};

int main() {
    Calculator calc;
    double a = 10.0;
    double b = 5.0;

    std::cout << "Addition: " << calc.add(a, b) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(a, b) << std::endl;
    std::cout << "Division: " << calc.divide(a, b) << std::endl;

    return 0;
}








