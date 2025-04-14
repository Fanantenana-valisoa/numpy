// transform_sort.hpp
#ifndef TRANSFORM_SORT_HPP
#define TRANSFORM_SORT_HPP

#include <vector>
#include <algorithm>

class TransformSort {
public:
    static std::vector<double> sort_ascending(const std::vector<double>& data);
    static std::vector<double> sort_descending(const std::vector<double>& data);
    static std::vector<double> reverse(const std::vector<double>& data);
};

#endif