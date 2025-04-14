// comparison.cpp
#include "Comparaison.hpp"
#include <stdexcept>

std::vector<bool> Comparison::equal(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vectors must be of the same size");
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] == b[i]);
    }
    return result;
}

std::vector<bool> Comparison::not_equal(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vectors must be of the same size");
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] != b[i]);
    }
    return result;
}

std::vector<bool> Comparison::greater(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vectors must be of the same size");
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] > b[i]);
    }
    return result;
}

std::vector<bool> Comparison::less(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vectors must be of the same size");
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] < b[i]);
    }
    return result;
}

std::vector<bool> Comparison::greater_equal(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vectors must be of the same size");
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] >= b[i]);
    }
    return result;
}

std::vector<bool> Comparison::less_equal(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vectors must be of the same size");
    std::vector<bool> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = (a[i] <= b[i]);
    }
    return result;
}

std::vector<double> Comparison::apply_mask(const std::vector<double>& data, const std::vector<bool>& mask) {
    if (data.size() != mask.size()) throw std::invalid_argument("Data and mask must be of the same size");
    std::vector<double> result;
    for (size_t i = 0; i < data.size(); ++i) {
        if (mask[i]) {
            result.push_back(data[i]);
        }
    }
    return result;
}
