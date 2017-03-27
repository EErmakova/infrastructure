#include <gtest/gtest.h>
#include "massive.h"

TEST(Massive, one_element) {
    int n = 1;
    int a[1] = { 4 };
    int* res = Multipl(a, 1);
    int check[1] = { 1 };
    for (int i = 0; i < n; ++i)
        EXPECT_EQ(res[i], check[i]);
}