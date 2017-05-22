#include <gtest/gtest.h>
#include "spanning_tree.h"
TEST(Prim, Can_work_with_empty_graph) {
    vector<vector<int>> g;
    vector<pair<int, pair<int, int>>> res = Prim(g, 0);
    EXPECT_TRUE(res.empty());
}
TEST(Prim, Can_work_with_already_spanning_tree) {
    vector<vector<int>> g =
    {{ 0, 10, INF, INF, INF },
     { 10, 0, 5, INF, INF },
     { INF, 5, 0, 8, 3 },
     { INF, INF, 8, 0, INF },
     { INF, INF, 3, INF, 8 } };
    vector<pair<int, pair<int, int>>> res = Prim(g, 0);
    vector<pair<int, pair<int, int>>> exp = {
        make_pair(10, make_pair(0, 1)),
        make_pair(5, make_pair(1, 2)),
        make_pair(3, make_pair(2, 4)),
        make_pair(8, make_pair(2, 3))
    };
    for (int i = 0; i < static_cast<int>(exp.size()); ++i)
        EXPECT_EQ(exp[i], res[i]);
}
TEST(Prim, Correct_work) {
    vector<vector<int>> g =
    { { 0, 5, INF, 2, 7 },
      { 5, 0, 8, INF, 1 },
      { INF, 8, 0, 5, 8 },
      { 2, INF, 5, 0, 4 },
      { 7, 1, 8, 4, 0 } };
    vector<pair<int, pair<int, int>>> res = Prim(g, 0);
    vector<pair<int, pair<int, int>>> exp =
    {   make_pair(2, make_pair(0, 3)),
        make_pair(4, make_pair(3, 4)),
        make_pair(1, make_pair(1, 4)),
        make_pair(5, make_pair(2, 3)),
    };
    for (int i = 0; i < static_cast<int>(exp.size()); ++i)
        EXPECT_EQ(exp[i], res[i]);
}
TEST(Prim, Cant_work_with_forest) {
    vector<vector<int>> g =
    { { 0, INF, 15, INF, 9 },
      { INF, 0, INF, 10, INF },
      { 15, INF, 0, INF, 1 },
      { INF, 10, INF, 0, INF },
      { 9, INF, 1, INF, 0 } };
    EXPECT_ANY_THROW(Prim(g, 0));
}
