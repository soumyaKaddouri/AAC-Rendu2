#include "Bezout.hpp"
#include <iostream>

int main() {
    std::pair<int, int> testCases[] = {
        {50, 11},  // Nombres positifs
        {-50, 11}, // Un des nombres est négatif
        {-50, -11}, // Les deux nombres sont négatifs
        {50, 0}, // Un des nombres est zéro
        {0, 0} // Les deux nombres sont zéro
    };

    for (const auto& testCase : testCases) {
        int a = testCase.first;
        int b = testCase.second;

        int gcd, x, y;
        std::tie(gcd, x, y) = extendedEuclidean(a, b);

        std::cout << "Bézout coefficients (x, y) for " << a << " and " << b << ": (" << x << ", " << y << ")" << std::endl;
        std::cout << "GCD of " << a << " and " << b << ": " << gcd << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
    }

    return 0;
}