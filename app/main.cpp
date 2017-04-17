#include "create_tree.h"
int main() {
    int n = 5;
    int a[5] = { 1, 3, 5, 7, 9 };
    CNode* res = Create_tree(a, n);
    std::cout << "root->right->val = "
        << res->right->val << ::std::endl;
    std::cout << "root->left->right->val = "
        << res->left->right->val << ::std::endl;
    CNode** new_res = find(&res, 8);
    *new_res = new CNode(8);
    std::cout << "root->right->right->left->val = "
        << res->right->right->left->val << ::std::endl;
    std::cout << "The tree:" << std::endl;
    PrintTree(res);
    return 0;
}
