#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

class Array {
private:
    std::vector<std::vector<double>> data;
    size_t rows, cols;

public:
    // Constructeurs
    Array(size_t rows, size_t cols);
    Array(const std::vector<std::vector<double>>& input);

    // Affichage
    void print() const;

    // Manipulations
    Array reshape(size_t new_rows, size_t new_cols) const;
    std::vector<double> flatten() const;
    Array transpose() const;
    Array hstack(const Array& other) const;
    Array vstack(const Array& other) const;
};

#endif