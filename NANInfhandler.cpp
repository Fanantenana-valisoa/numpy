// nan_inf_handler.cpp
#include "NANInfhandler.hpp"

std::vector<bool> NaNInfHandler::is_nan(const std::vector<double>& data) {
    std::vector<bool> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = std::isnan(data[i]);
    }
    return result;
}

std::vector<bool> NaNInfHandler::is_inf(const std::vector<double>& data) {
    std::vector<bool> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = std::isinf(data[i]);
    }
    return result;
}

std::vector<double> NaNInfHandler::replace_nan(const std::vector<double>& data, double value) {
    std::vector<double> result(data);
    for (size_t i = 0; i < data.size(); ++i) {
        if (std::isnan(data[i])) {
            result[i] = value;
        }
    }
    return result;
}

std::vector<double> NaNInfHandler::replace_inf(const std::vector<double>& data, double value) {
    std::vector<double> result(data);
    for (size_t i = 0; i < data.size(); ++i) {
        if (std::isinf(data[i])) {
            result[i] = value;
        }
    }
    return result;
}
