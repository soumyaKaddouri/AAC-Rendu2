#include "catch.hpp"
#include "source.hpp"
#include <vector>

TEST_CASE("Construction de l'arbre de segments") {
    std::vector<int> input = {3, -1, 4, 0, 2, 1};
    int n = input.size();
    std::vector<int> segment_tree(4 * n);
    build_tree(input, segment_tree, 0, n - 1, 0);
    
    SECTION("Vérification de la construction de l'arbre de segments") {
        REQUIRE(segment_tree[0] == -1);
        REQUIRE(segment_tree[1] == -1);
        REQUIRE(segment_tree[2] == 0);
        REQUIRE(segment_tree[3] == -1);
        REQUIRE(segment_tree[4] == 4);
        REQUIRE(segment_tree[5] == 0);
        REQUIRE(segment_tree[6] == 1);
        REQUIRE(segment_tree[7] == 3);
        REQUIRE(segment_tree[8] == -1);
        REQUIRE(segment_tree[9] == 0);
    }
}

TEST_CASE("Recherche du minimum dans une plage donnée (RMQ)") {
    std::vector<int> segment_tree = {-1, -1, 3, -1, 0, 2, 1};

    SECTION("Recherche du minimum dans la plage donnée") {
        // Recherche du minimum dans la plage [1, 5]
        REQUIRE(0 == find_min(segment_tree, 1, 5, 0, 5, 0));
        // Recherche du minimum dans la plage [2, 4]
        REQUIRE(0 == find_min(segment_tree, 2, 4, 0, 5, 0));
        // Recherche du minimum dans la plage [0, 3]
        REQUIRE(-1 == find_min(segment_tree, 0, 3, 0, 5, 0));
    }
}