// nan_inf_handler.hpp
#ifndef NAN_INF_HANDLER_HPP
#define NAN_INF_HANDLER_HPP

#include <vector>
#include <cmath>

class NaNInfHandler {
public:
    static std::vector<bool> is_nan(const std::vector<double>& data);
    static std::vector<bool> is_inf(const std::vector<double>& data);
    static std::vector<double> replace_nan(const std::vector<double>& data, double value);
    static std::vector<double> replace_inf(const std::vector<double>& data, double value);
};

#endif