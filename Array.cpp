#include "Array.hpp"

// Constructeur avec dimensions
Array::Array(size_t rows, size_t cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<double>(cols, 0.0));
}

// Constructeur avec données initiales
Array::Array(const std::vector<std::vector<double>>& input) {
    if (input.empty() || input[0].empty()) {
        throw std::invalid_argument("Input data cannot be empty.");
    }
    rows = input.size();
    cols = input[0].size();
    data = input;
}

// Affichage
void Array::print() const {
    for (const auto& row : data) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Redimensionnement
Array Array::reshape(size_t new_rows, size_t new_cols) const {
    if (rows * cols != new_rows * new_cols) {
        throw std::invalid_argument("Total size must remain the same for reshape.");
    }
    Array result(new_rows, new_cols);
    std::vector<double> flattened = flatten();
    size_t index = 0;
    for (size_t i = 0; i < new_rows; ++i) {
        for (size_t j = 0; j < new_cols; ++j) {
            result.data[i][j] = flattened[index++];
        }
    }
    return result;
}

// Aplatissement
std::vector<double> Array::flatten() const {
    std::vector<double> flattened;
    for (const auto& row : data) {
        flattened.insert(flattened.end(), row.begin(), row.end());
    }
    return flattened;
}

// Transposition
Array Array::transpose() const {
    Array result(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

// Concaténation horizontale
Array Array::hstack(const Array& other) const {
    if (rows != other.rows) {
        throw std::invalid_argument("Rows must match for horizontal stacking.");
    }
    Array result(rows, cols + other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j];
        }
        for (size_t j = 0; j < other.cols; ++j) {
            result.data[i][cols + j] = other.data[i][j];
        }
    }
    return result;
}

// Concaténation verticale
Array Array::vstack(const Array& other) const {
    if (cols != other.cols) {
        throw std::invalid_argument("Columns must match for vertical stacking.");
    }
    Array result(rows + other.rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j];
        }
    }
    for (size_t i = 0; i < other.rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[rows + i][j] = other.data[i][j];
        }
    }
    return result;
}