#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::pair;
using std::make_pair;
const int INF = 1000000;
vector<int> Dijkstra(int s, int n, vector<vector<pair<int, int>>> g);

#endif  // INCLUDE_DIJKSTRA_H_
