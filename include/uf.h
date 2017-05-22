#ifndef INCLUDE_UF_H_
#define INCLUDE_UF_H_
#include "spanning_tree.h"
int Find(vector<int> parent, int p) {
    int res = p;
    while (parent[res] != res) {
        res = parent[res];
    }
    return res;
}
void Union(vector<int>* parent, vector<int>* count, int p, int q) {
    int x = Find(*parent, p);
    int y = Find(*parent, q);
    if ((*count)[x] > (*count)[y]) {
        (*parent)[y] = x;
        (*count)[x]++;
    } else {
        (*parent)[x] = y;
        (*count)[y]++;
    }
}
#endif  // INCLUDE_UF_H_
