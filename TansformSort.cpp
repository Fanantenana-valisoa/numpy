// transform_sort.cpp
#include "TransformSort.hpp"

std::vector<double> TransformSort::sort_ascending(const std::vector<double>& data) {
    std::vector<double> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());
    return sorted_data;
}

std::vector<double> TransformSort::sort_descending(const std::vector<double>& data) {
    std::vector<double> sorted_data = data;
    std::sort(sorted_data.rbegin(), sorted_data.rend());
    return sorted_data;
}

std::vector<double> TransformSort::reverse(const std::vector<double>& data) {
    std::vector<double> reversed_data = data;
    std::reverse(reversed_data.begin(), reversed_data.end());
    return reversed_data;
}
