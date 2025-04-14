// linear_algebra.hpp
#ifndef LINEAR_ALGEBRA_HPP
#define LINEAR_ALGEBRA_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols, double value = 0.0);
    static Matrix identity(size_t size);
    static Matrix random(size_t rows, size_t cols);
    
    double& operator()(size_t i, size_t j);
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;
    double determinant() const;
    Matrix inverse() const;
    
    void print() const;
};

#endif