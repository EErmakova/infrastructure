#ifndef INCLUDE_ISLAND_H_
#define INCLUDE_ISLAND_H_

#include <vector>
#include <time.h>
#include <cstdlib>
using std::vector;
int Find(vector<int> a, int p);
void Union(vector<int>* a, vector<int>* b, int p, int q);
void Percolation(vector<vector<int>>* matrix);

#endif  // INCLUDE_ISLAND_H_
