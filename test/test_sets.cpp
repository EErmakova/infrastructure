#include <gtest/gtest.h>
#include "sets.h"

TEST(Join, Can_join_all_in_one) {
    vector<pair<int, int>> pairs;
    vector<int> res(6);
    res = Sets(6, pairs);
    for (int i = 0; i < 6; ++i)
        EXPECT_EQ(0, res[i]);
}
TEST(Join, Every_element_has_it_own_set) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < 6; ++i)
        for (int j = i + 1; j < 6; ++j)
            if (i != j)
                pairs.push_back(make_pair(i, j));
    vector<int> res(6);
    res = Sets(6, pairs);
    for (int i = 0; i < 6; ++i)
        EXPECT_EQ(i, res[i]);
}
TEST(Join, Can_join) {
    vector<pair<int, int>> pairs =
    { make_pair(0, 1), make_pair(0, 4),
     make_pair(1, 2), make_pair(1, 4),
     make_pair(2, 4),
     make_pair(3, 4) };
    vector<int> res(5);
    res = Sets(5, pairs);
    for (int i = 0; i < 6; ++i) {
        EXPECT_NE(res[0], res[1]);
        EXPECT_NE(res[0], res[4]);
        EXPECT_NE(res[1], res[2]);
        EXPECT_NE(res[1], res[4]);
        EXPECT_NE(res[2], res[4]);
        EXPECT_NE(res[3], res[4]);
        EXPECT_EQ(res[0], res[2]);
        EXPECT_EQ(res[0], res[3]);
        EXPECT_EQ(res[2], res[3]);
    }
}
