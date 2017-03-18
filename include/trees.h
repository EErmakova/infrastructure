#ifndef INCLUDE_TREES_H_
#define INCLUDE_TREES_H_
#include <iostream>
using std::cout;
using std::endl;
struct CNode {
    int val;
    CNode* left;
    CNode* right;
    explicit CNode(int v){ val = v; left = 0; right = 0; }
};
CNode* createTreeForTest();
CNode** find(CNode** root, int v);
bool print(CNode* root, int v);
void printAll(CNode* root);

#endif  // INCLUDE_TREES_H_
