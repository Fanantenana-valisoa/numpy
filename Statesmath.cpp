#include "Statesmath.hpp"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stdexcept>

// Moyenne des éléments du tableau
double StatsMath::mean(const Array& arr) {
    auto flat = arr.flatten();
    if (flat.empty()) throw std::invalid_argument("Array is empty.");
    return std::accumulate(flat.begin(), flat.end(), 0.0) / flat.size();
}

// Médiane des éléments
double StatsMath::median(const Array& arr) {
    auto flat = arr.flatten();
    if (flat.empty()) throw std::invalid_argument("Array is empty.");
    std::sort(flat.begin(), flat.end());
    size_t n = flat.size();
    return (n % 2 == 0) ? (flat[n/2 - 1] + flat[n/2]) / 2.0 : flat[n/2];
}

// Somme des éléments
double StatsMath::sum(const Array& arr) {
    auto flat = arr.flatten();
    return std::accumulate(flat.begin(), flat.end(), 0.0);
}

// Produit des éléments
double StatsMath::prod(const Array& arr) {
    auto flat = arr.flatten();
    if (flat.empty()) return 0.0;
    return std::accumulate(flat.begin(), flat.end(), 1.0, std::multiplies<double>());
}

// Valeur minimale
double StatsMath::min(const Array& arr) {
    auto flat = arr.flatten();
    if (flat.empty()) throw std::invalid_argument("Array is empty.");
    return *std::min_element(flat.begin(), flat.end());
}

// Valeur maximale
double StatsMath::max(const Array& arr) {
    auto flat = arr.flatten();
    if (flat.empty()) throw std::invalid_argument("Array is empty.");
    return *std::max_element(flat.begin(), flat.end());
}

// Indice de la valeur minimale (aplati)
size_t StatsMath::argmin(const Array& arr) {
    auto flat = arr.flatten();
    if (flat.empty()) throw std::invalid_argument("Array is empty.");
    return std::distance(flat.begin(), std::min_element(flat.begin(), flat.end()));
}

// Indice de la valeur maximale (aplati)
size_t StatsMath::argmax(const Array& arr) {
    auto flat = arr.flatten();
    if (flat.empty()) throw std::invalid_argument("Array is empty.");
    return std::distance(flat.begin(), std::max_element(flat.begin(), flat.end()));
}

// Variance (population = false pour variance échantillon)
double StatsMath::variance(const Array& arr, bool population) {
    double m = mean(arr);
    auto flat = arr.flatten();
    double sum_sq = std::accumulate(flat.begin(), flat.end(), 0.0,
        [m](double acc, double x) { return acc + (x - m) * (x - m); }
    );
    return sum_sq / (flat.size() - (population ? 0 : 1));
}

// Écart-type
double StatsMath::stddev(const Array& arr, bool population) {
    return std::sqrt(variance(arr, population));
}

// Somme cumulative
std::vector<double> StatsMath::cumsum(const Array& arr) {
    auto flat = arr.flatten();
    std::vector<double> result(flat.size());
    std::partial_sum(flat.begin(), flat.end(), result.begin());
    return result;
}

// Percentile (approche linéaire comme dans NumPy)
double StatsMath::percentile(const Array& arr, double q) {
    auto flat = arr.flatten();
    if (flat.empty()) throw std::invalid_argument("Array is empty.");
    std::sort(flat.begin(), flat.end());
    double index = (q / 100.0) * (flat.size() - 1);
    size_t lower = static_cast<size_t>(std::floor(index));
    size_t upper = static_cast<size_t>(std::ceil(index));
    double weight = index - lower;
    return flat[lower] * (1 - weight) + flat[upper] * weight;
}