#include <gtest/gtest.h>
#include "avl_tree.h"
TEST(AVLTree, Can_create_empty_tree) {
    EXPECT_NO_THROW(AVLTree<int> a);
}

TEST(AVLTree, Size_of_empty_tree_is_zero) {
    AVLTree<int> empty;
    EXPECT_EQ(0, empty.GetSize());
}

TEST(AVLTree, Can_insert_a_key) {
    AVLTree<int> a;
    EXPECT_NO_THROW(a.Add(7));
}

TEST(AVLTree, LeftRotation_works_correct) {
    AVLTree<int> a;
    for (int i = 2; i < 10; ++i)
        a.Add(i);
    int res = a.root->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    a.Add(1);
    res = a.root->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
}

TEST(AVLTree, RightRotation_works_correct) {
    AVLTree<int> a;
    for (int i = 2; i < 10; ++i)
        a.Add(i);
    int res = a.root->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    a.Add(10);
    res = a.root->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
}

TEST(AVLTree, DoubleRightRotation_works_correct) {
    AVLTree<int> a;
    for (int i = 30; i <= 70; i=i+10)
        a.Add(i);
    a.Add(5);
    int res = a.root->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    a.Add(20);
    res = a.root->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
}

TEST(AVLTree, Single_tree_is_balanced) {
    AVLTree<int> a;
    a.Add(7);
    EXPECT_TRUE(((a.root)->balance == -1) ||
        ((a.root)->balance == 0) || ((a.root)->balance == 0));
}

TEST(AVLTree, Can_insert_to_tree) {
    AVLTree<int> a;
    a.Add(2);
    a.Add(6);
    a.Add(7);
    avlnode<int>* eight = new avlnode<int>(8, nullptr);
    EXPECT_NO_THROW(a.Insert(&(a.root->left), &eight));
}

TEST(AVLTree, Adding_increases_size_tree) {
    AVLTree<int> a;
    int tmp = a.GetSize();
    a.Add(7);
    EXPECT_EQ(tmp + 1, a.GetSize());
}

TEST(AVLTree, Created_tree_is_correct) {
    AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    EXPECT_EQ(a.root->val, 3);
    EXPECT_EQ(a.root->left->val, 1);
    EXPECT_EQ(a.root->right->val, 7);
    EXPECT_EQ(a.root->left->left->val, 0);
    EXPECT_EQ(a.root->left->right->val, 2);
    EXPECT_EQ(a.root->right->left->val, 5);
    EXPECT_EQ(a.root->right->right->val, 8);
    EXPECT_EQ(a.root->right->left->left->val, 4);
    EXPECT_EQ(a.root->right->left->right->val, 6);
    EXPECT_EQ(a.root->right->right->right->val, 9);
}

TEST(AVLTree, Created_tree_is_correct_check_with_func) {
    AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    vector<int> v = {3, 7, 8, 9, 5, 6, 4, 1, 2, 0};
    vector<avlnode<int>*> knots = a.GetAllKnots();
    for (int i = 0; i < 10; ++i)
        EXPECT_EQ(v[i], knots[i]->val);
}

TEST(AVLTree, Adding_increases_size_tree_2) {
    AVLTree<int> a;
    int tmp = a.GetSize();
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    EXPECT_EQ(tmp + 10, a.GetSize());
}

TEST(AVLTree, Created_tree_is_balanced) {
    AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    int res = a.root->balance;
    EXPECT_TRUE((res ==-1) || (res == 0) || (res == 1));
    res = a.root->left->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    res = a.root->right->right->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
}

TEST(AVLTree, Can_erase_by_key) {
    AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    EXPECT_NO_THROW(a.Erase(7));
}

TEST(AVLTree, Can_erase_by_knot) {
    AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    EXPECT_NO_THROW(a.Erase(a.root->balance));
}

TEST(AVLTree, Erasing_decreases_size_tree_) {
    AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    int tmp = a.GetSize();
    a.Erase(1);
    a.Erase(4);
    EXPECT_EQ(tmp -2, a.GetSize());
}
TEST(AVLTree, Erase_saves_balance) {
    AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Add(i);
    int res = a.root->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    res = a.root->left->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    res = a.root->right->right->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    a.Erase(3);
    a.Erase(9);
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
    res = a.root->left->balance;
    EXPECT_TRUE((res == -1) || (res == 0) || (res == 1));
}
