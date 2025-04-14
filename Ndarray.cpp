#include "Ndarray.hpp"
#include <algorithm> // Pour std::fill

// Constructeur général
NdArray::NdArray(const std::vector<size_t>& shape, double value) : shape(shape) {
    total_size = 1;
    for (size_t dim : shape) total_size *= dim;
    data = new double[total_size];
    std::fill(data, data + total_size, value);
}

// Fonction pour créer un tableau rempli de zéros
NdArray NdArray::zeros(const std::vector<size_t>& shape) {
    return NdArray(shape, 0.0);
}

// Fonction pour créer un tableau rempli de uns
NdArray NdArray::ones(const std::vector<size_t>& shape) {
    return NdArray(shape, 1.0);
}

// Fonction pour créer un tableau rempli d'une valeur spécifique
NdArray NdArray::full(const std::vector<size_t>& shape, double value) {
    return NdArray(shape, value);
}

// Accès aux éléments (1D pour l'instant, il faudra améliorer pour le multi-indexing)
double& NdArray::operator()(size_t index) {
    return data[index];
}

// Affichage du tableau (simple, linéaire pour l'instant)
void NdArray::print() const {
    for (size_t i = 0; i < total_size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// Destructeur
NdArray::~NdArray() {
    delete[] data;
}