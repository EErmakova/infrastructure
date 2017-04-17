#include <gtest/gtest.h>
#include "trees.h"
TEST(TreeFind, Can_find_in_the_root) {
    CNode* root = createTreeForTest();
    EXPECT_EQ(*(find(&root, 5)), root);
}
TEST(TreeFind, Cant_find_defunct_elem) {
    CNode* root = createTreeForTest();
    CNode* nu = NULL;
    EXPECT_EQ(*(find(&root, 2)), nu);
}
TEST(TreeFind, Can_find_left_least) {
    CNode* root = createTreeForTest();
    CNode* act = (root->left)->left;
    EXPECT_EQ(*(find(&root, 1)), act);
}
TEST(TreeFind, Can_find_right_least) {
    CNode* root = createTreeForTest();
    CNode* act = (root->right)->right;
    EXPECT_EQ(*(find(&root, 10)), act);
}
TEST(TreeFind, Can_find_link_in_the_middle) {
    CNode* root = createTreeForTest();
    CNode* act = root->right;
    EXPECT_EQ(*(find(&root, 7)), act);
}
TEST(TreePrint, Can_print_root) {
    CNode* root = createTreeForTest();
    EXPECT_TRUE(print(root, 5));
}
TEST(TreePrint, Can_print_least) {
    CNode* root = createTreeForTest();
    EXPECT_TRUE(print(root, 10));
}
TEST(TreePrint, Can_print_middle_link) {
    CNode* root = createTreeForTest();
    EXPECT_TRUE(print(root, 7));
}
TEST(TreePrint, Cant_print_defunct_least) {
    CNode* root = createTreeForTest();
    EXPECT_TRUE(print(root, 1001));
}

TEST(TreePrint, Can_print_all_tree) {
    CNode* root = createTreeForTest();
    ASSERT_NO_THROW(printAll(root));
}
TEST(TreePrint, Can_add_and_print) {
    CNode* root = createTreeForTest();
    cout << "----Old tree----" << endl;
    ASSERT_NO_THROW(printAll(root));
    CNode** res = find(&root, 2);
    *res = new CNode(2);
    cout << "----New tree----" << endl;
    ASSERT_NO_THROW(printAll(root));
    int act = root->left->left->right->val;
    EXPECT_EQ(act, 2);
}
