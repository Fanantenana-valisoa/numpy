// linear_algebra.cpp
#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <cstdlib>

Matrix::Matrix(size_t rows, size_t cols, double value) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<double>(cols, value));
}

Matrix Matrix::identity(size_t size) {
    Matrix I(size, size, 0.0);
    for (size_t i = 0; i < size; ++i) {
        I(i, i) = 1.0;
    }
    return I;
}

Matrix Matrix::random(size_t rows, size_t cols) {
    Matrix R(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            R(i, j) = static_cast<double>(rand()) / RAND_MAX;
        }
    }
    return R;
}

double& Matrix::operator()(size_t i, size_t j) {
    if (i >= rows || j >= cols) throw std::out_of_range("Index out of bounds");
    return data[i][j];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) throw std::invalid_argument("Matrix dimensions must match");
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) throw std::invalid_argument("Matrix dimensions must match");
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) throw std::invalid_argument("Incompatible matrix dimensions for multiplication");
    Matrix result(rows, other.cols, 0.0);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(j, i) = data[i][j];
        }
    }
    return result;
}

double Matrix::determinant() const {
    if (rows != cols) throw std::invalid_argument("Matrix must be square");
    // Méthode de Gauss (à améliorer)
    double det = 1.0;
    Matrix temp = *this;
    for (size_t i = 0; i < rows; ++i) {
        if (temp(i, i) == 0) return 0;
        for (size_t j = i + 1; j < rows; ++j) {
            double ratio = temp(j, i) / temp(i, i);
            for (size_t k = i; k < cols; ++k) {
                temp(j, k) -= ratio * temp(i, k);
            }
        }
        det *= temp(i, i);
    }
    return det;
}

Matrix Matrix::inverse() const {
    if (rows != cols) throw std::invalid_argument("Matrix must be square");
    // Implémentation simplifiée (à améliorer avec pivot de Gauss)
    throw std::runtime_error("Inverse not implemented yet");
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
