#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <vector>

void build_tree(std::vector<int>& input, std::vector<int>& segment_tree, int low, int high, int position);
int find_min(std::vector<int>& segment_tree, int qlow, int qhigh, int low, int high, int position);
int find_min_in_segment_tree(std::vector<int>& segment_tree, int qlow, int qhigh, int n);

#endif