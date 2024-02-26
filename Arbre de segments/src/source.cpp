#include "source.hpp"

#include <vector>
#include <climits> // Pour INT_MAX

void build_tree(std::vector<int>& input, std::vector<int>& segment_tree, int low, int high, int position) {
    if (low == high) {
        segment_tree[position] = input[low]; // Stocke la valeur du nœud feuille dans l'arbre de segments
    } else {
        int mid = (low + high) / 2;
        build_tree(input, segment_tree, low, mid, 2 * position + 1); // Appel récursif pour le fils gauche
        build_tree(input, segment_tree, mid + 1, high, 2 * position + 2); // Appel récursif pour le fils droit
        segment_tree[position] = std::min(segment_tree[2 * position + 1], segment_tree[2 * position + 2]); // Calcule la valeur du nœud actuel
    }
}

// Fonction récursive pour trouver le minimum dans une plage donnée (RMQ)
int find_min(std::vector<int>& segment_tree, int qlow, int qhigh, int low, int high, int position) {
    if (qlow <= low && qhigh >= high) { // Superposition totale
        return segment_tree[position]; // Retourne la valeur du noeud actuel
    }
    if (qlow > high || qhigh < low) { // Pas de chevauchement
        return INT_MAX; // Retourne une valeur maximale
    }
    int mid = (low + high) / 2;
    return std::min(find_min(segment_tree, qlow, qhigh, low, mid, 2 * position + 1), // Cherche dans le fils gauche
               find_min(segment_tree, qlow, qhigh, mid + 1, high, 2 * position + 2)); // Cherche dans le fils droit
}

// Fonction pour trouver le minimum dans une plage donnée (RMQ)
int find_min_in_segment_tree(std::vector<int>& segment_tree, int qlow, int qhigh, int n) {
    if (qlow < 0 || qhigh >= n || qlow > qhigh) {
        return INT_MAX; // Retourne une valeur maximale
    }
    return find_min(segment_tree, qlow, qhigh, 0, n - 1, 0); // Appel initial à la fonction récursive
}