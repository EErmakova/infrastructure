#include "trees.h"
CNode* createTreeForTest() {
    CNode* root = new CNode(5);
    root->left = new CNode(3);
    root->right = new CNode(7);
    (root->left)->left = new CNode(1);
    (root->left)->right = new CNode(4);
    (root->right)->left = new CNode(6);
    (root->right)->right = new CNode(10);
    return root;
}
CNode** find(CNode**root, int v) {
    while (*root) {
        if ((*root)->val == v) {
            return root;
        } else {
            if ((*root)->val < v) {
                root = &(*root)->right;
            } else {
                root = &(*root)->left;
            }
        }
    }
    return root;
}

bool print(CNode* root, int v) {
    CNode* tmp = *(find(&root, v));
    if (!tmp) {
        cout << "The element is not found" << endl;
        return true;
    } else {
        cout << "Address of the left subtree: "
            << tmp->left << endl;
        if (tmp->left)
            cout << "Knot of the left subtree: "
            << tmp->left->val << endl;
        cout << "Address of the right subtree: "
            << tmp->right << endl;
        if (tmp->right)
            cout << "Knot of the right subtree: "
            << tmp->right->val << endl;
        cout << "Knot of this link: "
            << tmp->val << endl;
        return true;
    }
    return false;
}
void printAll(CNode* root) {
    if (root) {
        printAll(root->left);
        cout << root << "  " << root->val << "  "
            << root->left << "  " << root->right << endl;
       printAll(root->right);
    }
}
