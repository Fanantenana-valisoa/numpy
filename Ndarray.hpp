#ifndef NDARRAY_HPP
#define NDARRAY_HPP

#include <vector>
#include <iostream>

class NdArray {
public:
    // Constructeur général
    NdArray(const std::vector<size_t>& shape, double value = 0.0);

    // Fonction pour créer un tableau rempli de zéros
    static NdArray zeros(const std::vector<size_t>& shape);

    // Fonction pour créer un tableau rempli de uns
    static NdArray ones(const std::vector<size_t>& shape);

    // Fonction pour créer un tableau rempli d'une valeur spécifique
    static NdArray full(const std::vector<size_t>& shape, double value);

    // Accès aux éléments (1D pour l'instant, il faudra améliorer pour le multi-indexing)
    double& operator()(size_t index);

    // Affichage du tableau (simple, linéaire pour l'instant)
    void print() const;

    // Destructeur
    ~NdArray();

private:
    std::vector<size_t> shape;
    size_t total_size;
    double* data;
};

#endif // NDARRAY_HPP