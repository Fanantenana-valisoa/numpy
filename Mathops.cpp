// math_operations.cpp
#include "Mathops.hpp"
#include <stdexcept>
#include <cmath>

double MathOps::add(double a, double b) {
    return a + b;
}

double MathOps::subtract(double a, double b) {
    return a - b;
}

double MathOps::multiply(double a, double b) {
    return a * b;
}

double MathOps::divide(double a, double b) {
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}

double MathOps::power(double base, double exp) {
    return std::pow(base, exp);
}

double MathOps::sqrt(double value) {
    if (value < 0) throw std::runtime_error("Cannot compute square root of negative number");
    return std::sqrt(value);
}

double MathOps::log(double value) {
    if (value <= 0) throw std::runtime_error("Logarithm undefined for non-positive values");
    return std::log(value);
}

double MathOps::exp(double value) {
    return std::exp(value);
}