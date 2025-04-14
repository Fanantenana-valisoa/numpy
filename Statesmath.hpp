#ifndef STATSMATH_HPP
#define STATSMATH_HPP

#include "Array.hpp"  // Inclure la classe Array précédente

class StatsMath {
public:
    // Fonctions statistiques de base
    static double mean(const Array& arr);
    static double median(const Array& arr);
    static double sum(const Array& arr);
    static double prod(const Array& arr);
    static double min(const Array& arr);
    static double max(const Array& arr);
    
    // Fonctions avancées
    static double variance(const Array& arr, bool population = false);
    static double stddev(const Array& arr, bool population = false);
    static std::vector<double> cumsum(const Array& arr);
    static double percentile(const Array& arr, double q);
    
    // Indices et positions
    static size_t argmin(const Array& arr);
    static size_t argmax(const Array& arr);
};

#endif