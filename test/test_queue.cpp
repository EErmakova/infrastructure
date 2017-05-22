#include <gtest/gtest.h>
#include "priority_queue.h"
/*on Heap*/
TEST(QUEUEonHeap, Can_create_empty_queue) {
    EXPECT_NO_THROW(Queue_on_heap<int> a);
}
TEST(QUEUEonHeap, Is_Empty_works_correctly) {
    Queue_on_heap<int> a;
    EXPECT_TRUE(a.IsEmpty());
}
TEST(QUEUEonHeap, Size_of_empty_queue_is_zero) {
    Queue_on_heap<int> a;
    EXPECT_EQ(0, a.GetSize());
}
TEST(QUEUEonHeap, Can_push) {
    Queue_on_heap<int> a;
    EXPECT_NO_THROW(a.Push(7));
}
TEST(QUEUEonHeap, Pushing_increase_size) {
    Queue_on_heap<int> a;
    int size1 = a.GetSize();
    a.Push(7);
    a.Push(3);
    int size2 = a.GetSize();
    EXPECT_EQ(size1 + 2, size2);
}
TEST(QUEUEonHeap, Is_Full_works_correctly) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 1000; ++i)
        a.Push(i);
    EXPECT_TRUE(a.IsFull());
}
TEST(QUEUEonHeap, Cant_push_to_full_queue) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 1000; ++i)
        a.Push(i);
    EXPECT_ANY_THROW(a.Push(1001));
}
TEST(QUEUEonHeap, Can_pop) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    EXPECT_NO_THROW(a.Pop());
}
TEST(QUEUEonHeap, Cant_pop_from_empty_queue) {
    Queue_on_heap<int> a;
    EXPECT_ANY_THROW(a.Pop());
}
TEST(QUEUEonHeap, Popping_decrease_size) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    int size1 = a.GetSize();
    a.Pop();
    int size2 = a.GetSize();
    EXPECT_EQ(size1 - 1, size2);
}
TEST(QUEUEonHeap, Top_works_correctly) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    EXPECT_EQ(0, a.Top());
}
TEST(QUEUEonHeap, Cant_Top_from_empty_queue) {
    Queue_on_heap<int> a;
    EXPECT_ANY_THROW(a.Top());
}
TEST(QUEUEonHeap, After_pop_Top_is_still_correct) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    a.Pop();
    EXPECT_EQ(1, a.Top());
}
TEST(QUEUEonHeap, Top_plus_pop_works_correctly) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    int mas[10];
    for (int i = 0; i < 10; ++i) {
        mas[i] = a.Top();
        a.Pop();
    }
    int exp[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < 10; ++i)
        EXPECT_EQ(mas[i], exp[i]);
}
TEST(QUEUEonHeap, Pushing_update_queue) {
    Queue_on_heap<int> a;
    for (int i = 1; i < 10; ++i)
        a.Push(i);
    EXPECT_EQ(1, a.Top());
    a.Push(0);
    EXPECT_EQ(0, a.Top());
}
TEST(QUEUEonHeap, After_total_pop_heap_is_empty) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 100; ++i)
        a.Push(i - i/2);
    for (int i = 0; i < 100; ++i)
        a.Pop();
    EXPECT_TRUE(a.IsEmpty());
}
/*on AVL-tree*/
TEST(QUEUEonAVLtree, Can_create_empty_queue) {
    EXPECT_NO_THROW(Queue_on_AVLTree<int> a);
}
TEST(QUEUEonAVLtree, Is_Empty_works_correctly) {
    Queue_on_AVLTree<int> a;
    EXPECT_TRUE(a.IsEmpty());
}
TEST(QUEUEonAVLtree, Size_of_empty_queue_is_zero) {
    Queue_on_AVLTree<int> a;
    EXPECT_EQ(0, a.GetSize());
}
TEST(QUEUEonAVLtree, Can_push) {
    Queue_on_AVLTree<int> a;
    EXPECT_NO_THROW(a.Push(7));
}
TEST(QUEUEonAVLtree, Pushing_increase_size) {
    Queue_on_AVLTree<int> a;
    int size1 = a.GetSize();
    a.Push(7);
    a.Push(3);
    int size2 = a.GetSize();
    EXPECT_EQ(size1 + 2, size2);
}
TEST(QUEUEonAVLtree, Is_Full_works_correctly) {
    Queue_on_AVLTree<int> a;
    for (int i = 0; i < 1000; ++i)
        a.Push(i);
    EXPECT_TRUE(!a.IsFull());
}
TEST(QUEUEonAVLtree, Can_pop) {
    Queue_on_AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    EXPECT_NO_THROW(a.Pop());
}
TEST(QUEUEonAVLtree, Cant_pop_from_empty_queue) {
    Queue_on_AVLTree<int> a;
    EXPECT_ANY_THROW(a.Pop());
}

TEST(QUEUEonAVLtree, Popping_decrease_size) {
    Queue_on_AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    int size1 = a.GetSize();
    a.Pop();
    int size2 = a.GetSize();
    EXPECT_EQ(size1 - 1, size2);
}

TEST(QUEUEonAVLtree, Top_works_correctly) {
    Queue_on_AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    EXPECT_EQ(0, a.Top());
}
TEST(QUEUEonAVLtree, Cant_Top_from_empty_queue) {
    Queue_on_AVLTree<int> a;
    EXPECT_ANY_THROW(a.Top());
}
TEST(QUEUEonAVLtree, After_pop_Top_is_still_correct) {
    Queue_on_AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    a.Pop();
    EXPECT_EQ(1, a.Top());
}
TEST(QUEUEonAVLtree, Top_plus_pop_works_correctly) {
    Queue_on_AVLTree<int> a;
    for (int i = 0; i < 10; ++i)
        a.Push(i);
    int mas[10];
    for (int i = 0; i < 10; ++i) {
        mas[i] = a.Top();
        a.Pop();
    }
    int exp[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < 10; ++i)
        EXPECT_EQ(mas[i], exp[i]);
}
TEST(QUEUEonAVLtree, Pushing_update_queue) {
    Queue_on_AVLTree<int> a;
    for (int i = 1; i < 10; ++i)
        a.Push(i);
    EXPECT_EQ(1, a.Top());
    a.Push(0);
    EXPECT_EQ(0, a.Top());
}
TEST(QUEUEonAVLtree, After_total_pop_heap_is_empty) {
    Queue_on_AVLTree<int> a;
    for (int i = 0; i < 100; ++i)
        a.Push(i - i / 2);
    for (int i = 0; i < 100; ++i)
        a.Pop();
    EXPECT_TRUE(a.IsEmpty());
}
