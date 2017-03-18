#include "create_tree.h"
#include <queue>
CNode* Create_triangle_tree(int* a, int n) {
    CNode* root = nullptr;
    CNode* tmp = new CNode();
    std::queue<int> q;
    if (n == 0)
        return root;
    root = new CNode(a[n / 2]);
    tmp = root;
    for (int i = n / 2 - 1; i > 0; --i) {
        CNode* new_knot = new CNode(i);
        tmp->left = new_knot;
        tmp = new_knot;
    }
    for (int i = n / 2 + 1; i < n; ++i) {
        CNode* new_knot = new CNode(i);
        tmp->right = new_knot;
        tmp = new_knot;
    }
    return root;
}
CNode* Create_tree(int * a, int n) {
    CNode* root = nullptr;
    int begin = 0;
    int end = n - 1;
    int mid;
    std::queue<int> q;
    q.push(begin);
    q.push(end);
    while (!q.empty()) {
        begin = q.front();
        q.pop();
        end = q.front();
        q.pop();
        if (end < begin) {
            continue;
        }
        mid = (begin + end) / 2;
        CNode** tmp = find(&root, a[mid]);
        *tmp = new CNode(a[mid]);
        q.push(begin);
        q.push(mid - 1);
        q.push(mid + 1);
        q.push(end);
    }
    return root;
}
CNode** find(CNode**root, int v) {
    while (*root) {
        if ((*root)->val == v) {
            return root;
        }
        else {
            if ((*root)->val < v) {
                root = &(*root)->right;
            }
            else {
                root = &(*root)->left;
            }
        }
    }
    return root;
}
void PrintTree(CNode* root) {
    std::queue <CNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            CNode* e = q.front();
            q.pop();
            if (e == nullptr)
                continue;
            std::cout << e->val << " ";
            q.push(e->left);
            q.push(e->right);
        }
        std::cout << std::endl;
    }
}
