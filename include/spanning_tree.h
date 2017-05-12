#ifndef INCLUDE_SPANNING_TREE_H_
#define INCLUDE_SPANNING_TREE_H_
#include <algorithm>
#include <vector>
#include <utility>
using std::vector;
using std::pair;
using std::make_pair;
const int INF = 100000000;
vector<pair<int, pair<int, int>>> Kruskal(vector<vector<pair<int, int>>> g);
vector<pair<int, pair<int, int>>> Prim(vector<vector<int>> g, int st);
#endif  // INCLUDE_SPANNING_TREE_H_

