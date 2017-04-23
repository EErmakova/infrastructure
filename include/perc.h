#ifndef INCLUDE_PERC_H_
#define INCLUDE_PERC_H_
#include <vector>
#include <time.h>
#include <cstdlib>
using std::vector;
int Find(vector<int> a, int p);
void Union(vector<int>* a, vector<int>* b, int p, int q);
bool Percolation(vector<vector<int>> matrix);

double Probability(int n, int k);

#endif  // INCLUDE_PERC_H_


