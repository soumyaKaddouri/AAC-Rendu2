#include "Bezout.hpp"

std::tuple<int, int, int> extendedEuclidean(int a, int b) {
    if (b == 0) {
        return std::make_tuple(a, 1, 0);
    } else {
        int gcd, x1, y1;
        std::tie(gcd, x1, y1) = extendedEuclidean(b, a % b);
        int x = y1;
        int y = x1 - (a / b) * y1;
        return std::make_tuple(gcd, x, y);
    }
}
