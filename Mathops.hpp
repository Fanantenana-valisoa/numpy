// math_operations.hpp
#ifndef MATH_OPERATIONS_HPP
#define MATH_OPERATIONS_HPP

#include <vector>
#include <cmath>
#include <stdexcept>

class MathOps {
public:
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);
    static double power(double base, double exp);
    static double sqrt(double value);
    static double log(double value);
    static double exp(double value);
};

#endif
