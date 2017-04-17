#include <gtest/gtest.h>
#include "massive.h"

TEST(Multiply, correct_work) {
    const int n = 5;
    int a[5] = { 1, 2, 3, 4, 2 };
    int exp[5] = { 48, 24, 16, 12, 24 };
    int* res = Multiply(a, n);
    for (int i = 0; i < n; ++i)
        EXPECT_EQ(res[i], exp[i]);
}
TEST(Multiply, correct_work_with_empty_massive) {
    const int n = 0;
    int* a = nullptr;
    EXPECT_ANY_THROW(Multiply(a, n));
}
TEST(Multiply, correct_work_with_one_element_massive) {
    const int n = 1;
    int a[1] = { 20 };
    int exp[1] = { 1 };
    int* res = Multiply(a, n);
    for (int i = 0; i < n; ++i)
        EXPECT_EQ(res[i], exp[i]);
}
TEST(Multiply, correct_work_with_same_elements_massive) {
    const int n = 5;
    int a[5] = { 2, 2, 2, 2, 2 };
    int* res = Multiply(a, n);
    for (int i = 0; i < n; ++i)
        EXPECT_EQ(res[i], 16);
}
