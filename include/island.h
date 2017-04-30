#ifndef INCLUDE_ISLAND_H_
#define INCLUDE_ISLAND_H_

#include <vector>
#include <time.h>
#include <cstdlib>
#include <queue>
#include <iostream>
using std::vector;
using std::queue;
using std::cout;
using std::endl;

int const INF = 1000000;
struct coord {
    int str;
    int col;
};

int Find(vector<int> a, int p);
void Union(vector<int>* a, vector<int>* b, int p, int q);
void Percolation(vector<vector<int>>* matrix);
void BFS(vector<vector<int>>* matrix);

#endif  // INCLUDE_ISLAND_H_
