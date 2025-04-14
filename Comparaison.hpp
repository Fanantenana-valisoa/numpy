// comparison.hpp
#ifndef COMPARISON_HPP
#define COMPARISON_HPP

#include <vector>

class Comparison {
public:
    static std::vector<bool> equal(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<bool> not_equal(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<bool> greater(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<bool> less(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<bool> greater_equal(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<bool> less_equal(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<double> apply_mask(const std::vector<double>& data, const std::vector<bool>& mask);
};

#endif