#include <gtest/gtest.h>
#include "create_tree.h"

TEST(CreateTriangleTree, CanCreateEmptyTree) {
    EXPECT_NO_THROW(Create_triangle_tree(NULL, 0));
}
TEST(CreateTriangleTree, CanCreateSimpleTree) {
    int n = 3;
    int a[3] = { 0, 1, 2 };
    CNode* root = new CNode(1);
    CNode* current = Create_triangle_tree(a, n);
    EXPECT_EQ(current->val, root->val);
}
TEST(CreateTriangleTree, CanWorkWithTree) {
    int n = 3;
    int a[3] = { 0, 1, 2 };
    CNode* root = nullptr;
    root = Create_triangle_tree(a, n);
    EXPECT_EQ(*(find(&root, 0)), root->left);
}
TEST(CreateTree, can_create_bal_tree) {
    int n = 5;
    int a[5] = { 1, 3, 5, 7, 9 };
    EXPECT_NO_THROW(Create_tree(a, n));
}
TEST(CreateTree, can_correct_create_bal_tree) {
    int n = 5;
    int a[5] = { 1, 3, 5, 7, 9 };
    CNode* res = Create_tree(a, n);
    EXPECT_EQ(res->val, 5);
    EXPECT_EQ(res->left->val, 1);
    EXPECT_EQ(res->right->val, 7);
    EXPECT_EQ(res->left->right->val, 3);
    EXPECT_EQ(res->right->right->val, 9);
}
TEST(CreateTree, can_print_bal_tree) {
    int n = 6;
    int a[6] = { 1, 2, 3, 4, 5, 6 };
    EXPECT_NO_THROW(PrintTree(Create_tree(a, n)));
}
TEST(CreateTree, can_add_and_print_tree) {
    int n = 5;
    int a[5] = { 1, 2, 3, 4, 5 };
    CNode* root = Create_tree(a, n);
    PrintTree(root);
    CNode** tmp = find(&root, 6);
    *tmp = new CNode(6);
    EXPECT_NO_THROW(PrintTree(root));
}
