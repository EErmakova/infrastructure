#include <gtest/gtest.h>
#include "five_heap.h"
TEST(FIVEheap, Can_create_empty_heap) {
    EXPECT_NO_THROW(FIVEheap<int> a);
}
TEST(FIVEheap, Return_correct_size) {
    FIVEheap<int> a;
    EXPECT_EQ(0, a.GetSize());
}

TEST(FIVEheap, Can_insert) {
    FIVEheap<int> a;
    EXPECT_NO_THROW(a.Insert(7));
}
TEST(FIVEheap, Adding_increase_size) {
    FIVEheap<int> a;
    int size1 = a.GetSize();
    a.Insert(7);
    int size2 = a.GetSize();
    EXPECT_EQ(size1 + 1, size2);
}
TEST(FIVEheap, Cant_insert_to_full_heap) {
    FIVEheap<int> a;
    for (int i = 0; i < 1000; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.Insert(1001));
}

TEST(FIVEheap, Can_compare_equal_heaps) {
    FIVEheap<int> a;
    FIVEheap<int> b;
    for (int i = 0; i < 10; i++) {
        a.Insert(i);
        b.Insert(i);
    }
    EXPECT_TRUE(a == b);
}
TEST(FIVEheap, Cant_compare_not_equal_heaps) {
    FIVEheap<int> a;
    FIVEheap<int> b;
    for (int i = 0; i < 10; i++) {
        a.Insert(i);
        b.Insert(10-i);
    }
    EXPECT_FALSE(a == b);
}
TEST(FIVEheap, Cant_compare_not_equal_heaps2) {
    FIVEheap<int> a;
    FIVEheap<int> b;
    for (int i = 0; i < 10; i++) {
        a.Insert(i);
        b.Insert(10 - i);
    }
    EXPECT_TRUE(a != b);
}
TEST(FIVEheap, Can_get_elem_by_index) {
    FIVEheap<int> a;
    a.Insert(7);
    a.Insert(2);
    a.Insert(9);
    EXPECT_EQ(9, a[2]);
}
TEST(FIVEheap, Square_brackets_cant_work_with_neg_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a[-5]);
}
TEST(FIVEheap, Square_brackets_cant_work_with_too_much_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a[5]);
}
TEST(FIVEheap, Square_brackets_cant_change_size) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    int size1 = a.GetSize();
    int b = a[2];
    int size2 = a.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(FIVEheap, MinChild_cant_work_with_neg_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.MinChild(-10));
}
TEST(FIVEheap, MinChild_cant_work_with_too_much_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.MinChild(10));
}
TEST(FIVEheap, MinChild_cant_change_size) {
    FIVEheap<int> a;
    a.Insert(4);
    a.Insert(8);
    a.Insert(3);
    int size1 = a.GetSize();
    int r = a.MinChild(2);
    int size2 = a.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(FIVEheap, Can_correct_swap) {
    FIVEheap<int> a;
    a.Insert(4);
    a.Insert(8);
    a.Insert(3);
    a.Insert(12);
    a.Swap(0, 3);
    EXPECT_EQ(a[0], 12);
    EXPECT_EQ(a[3], 3);
}
TEST(FIVEheap, Swap_cant_work_with_neg_index) {
    FIVEheap<int> a;
    a.Insert(4);
    a.Insert(8);
    a.Insert(3);
    a.Insert(12);
    EXPECT_ANY_THROW(a.Swap(0, -3));
}
TEST(FIVEheap, Swap_cant_work_with_too_much_index) {
    FIVEheap<int> a;
    a.Insert(4);
    a.Insert(8);
    a.Insert(3);
    a.Insert(12);
    EXPECT_ANY_THROW(a.Swap(10, 2));
}
TEST(FIVEheap, Swap_cant_change_size) {
    FIVEheap<int> a;
    a.Insert(4);
    a.Insert(8);
    a.Insert(3);
    a.Insert(12);
    int size1 = a.GetSize();
    a.Swap(0, 1);
    int size2 = a.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(FIVEheap, Can_correctly_reduction) {
    FIVEheap<int> a;
    a.Insert(7);
    a.Reduction(0, -1);
    EXPECT_EQ(a[0], 8);
}
TEST(FIVEheap, Reduction_cant_work_with_neg_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.Reduction(-2, 5));
}
TEST(FIVEheap, Reduction_cant_work_with_too_much_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.Reduction(5, 5));
}
TEST(FIVEheap, Reduction_cant_change_size) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    int size1 = a.GetSize();
    a.Reduction(2, 4);
    int size2 = a.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(FIVEheap, Immertion_cant_work_with_neg_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.Immertion(-10));
}
TEST(FIVEheap, Immertion_cant_work_with_too_much_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.Immertion(10));
}
TEST(FIVEheap, Immertion_cant_change_size) {
    FIVEheap<int> a;
    a.Insert(4);
    a.Insert(8);
    a.Insert(3);
    int size1 = a.GetSize();
    a.Immertion(0);
    int size2 = a.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(FIVEheap, Emertion_cant_work_with_neg_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.Emertion(-10));
}
TEST(FIVEheap, Emertion_cant_work_with_too_much_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 3; i++)
        a.Insert(i);
    EXPECT_ANY_THROW(a.Emertion(10));
}
TEST(FIVEheap, Emertion_cant_change_size) {
    FIVEheap<int> a;
    a.Insert(4);
    a.Insert(8);
    a.Insert(3);
    int size1 = a.GetSize();
    a.Emertion(0);
    int size2 = a.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(FIVEheap, Can_erase) {
    FIVEheap<int> a;
    for (int i = 0; i < 10; i++)
        a.Insert(i);
    a.Erase(0);
    a.Erase(1);
    a.Erase(4);
    int mas[6] = {1, 7, 2, 3, 8, 5 };
    for (int i = 0; i < 6; i++)
        EXPECT_EQ(a[i], mas[i]);
}
TEST(FIVEheap, Cant_erase_from_empty_heap) {
    FIVEheap<int> a;
    EXPECT_ANY_THROW(a.Erase(0));
}
TEST(FIVEheap, Cant_erase_min_from_empty_heap) {
    FIVEheap<int> a;
    EXPECT_ANY_THROW(a.EraseMin());
}
TEST(FIVEheap, Erasing_decreases_size) {
    FIVEheap<int> a;
    for (int i = 0; i < 10; i++)
        a.Insert(i);
    int size1 = a.GetSize();
    a.Erase(0);
    a.Erase(1);
    a.Erase(4);
    int size2 = a.GetSize();
    EXPECT_EQ(size1 - 3, size2);
}
TEST(FIVEheap, ErasingMin_decreases_size) {
    FIVEheap<int> a;
    for (int i = 0; i < 10; i++)
        a.Insert(i);
    int size1 = a.GetSize();
    a.EraseMin();
    int size2 = a.GetSize();
    EXPECT_EQ(size1 - 1, size2);
}
TEST(FIVEheap, Erasing_cant_work_with_neg_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 10; i++)
        a.Insert(i);
    a.Erase(0);
    EXPECT_ANY_THROW(a.Erase(-4));
}
TEST(FIVEheap, Erace_cant_work_with_too_much_index) {
    FIVEheap<int> a;
    for (int i = 0; i < 10; i++)
        a.Insert(i);
    a.Erase(0);
    EXPECT_ANY_THROW(a.Erase(20));
}
TEST(FIVEheap, IsFull_works_correctly) {
    FIVEheap<int> a;
    for (int i = 0; i < 1000; i++)
        a.Insert(i);
    EXPECT_TRUE(a.IsFull());
}
TEST(FIVEheap, IsEmpty_works_correctly) {
    FIVEheap<int> a;
    EXPECT_TRUE(a.IsEmpty());
}
