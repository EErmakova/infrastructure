#ifndef INCLUDE_CREATE_TREE_H_
#define INCLUDE_CREATE_TREE_H_
#include <iostream>
struct CNode {
    CNode* left;
    CNode* right;
    int val;
    CNode() {}
    explicit CNode(int val_) {
        val = val_;
        left = nullptr;
        right = nullptr;
    }
};

CNode* Create_triangle_tree(int* a, int n);
CNode* Create_tree(int* a, int n);
CNode** find(CNode**root, int v);
void PrintTree(CNode* root);


#endif  // INCLUDE_CREATE_TREE_H_
