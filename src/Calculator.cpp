#include "Calculator.h"
#include <cmath>
#include <stdexcept>

double Calculator::squareRoot(double x) const {
    if (x < 0) {
        throw std::invalid_argument("Square root of negative number is not allowed");
    }
    return std::sqrt(x);
}

unsigned long long Calculator::factorial(int x) const {
    if (x < 0) {
        throw std::invalid_argument("Factorial of negative number is not allowed");
    }

    unsigned long long result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}

double Calculator::naturalLog(double x) const {
    if (x <= 0) {
        throw std::invalid_argument("Natural log is only defined for positive numbers");
    }
    return std::log(x);
}

double Calculator::power(double base, double exponent) const {
    return std::pow(base, exponent);
}