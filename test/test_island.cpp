#include <gtest/gtest.h>
#include "island.h"

TEST(IslandPercolation, Correct_work) {
    vector<vector<int>> g(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i)
        g[i][5] = 1;
    g[0][7] = 1;
    g[1][1] = 1;
    g[1][2] = 1;
    g[1][8] = 1;
    g[2][2] = 1;
    g[4][3] = 1;
    g[4][4] = 1;
    g[5][1] = 1;
    g[5][3] = 1;
    g[6][3] = 1;
    g[7][8] = 1;
    g[8][0] = 1;
    g[8][1] = 1;
    g[8][8] = 1;
    g[9][0] = 1;
    g[9][1] = 1;
    vector<vector<int>> n = g;
    n[1][1]= 0;
    n[1][2]= 0;
    n[1][8]= 0;
    n[2][2]= 0;
    n[5][1]= 0;
    n[7][8]= 0;
    n[8][8]= 0;
    Percolation(&g);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            EXPECT_EQ(g[i][j], n[i][j]);
}
TEST(IslandPercolation, All_live) {
    vector<vector<int>> g(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        g[i][0] = 1;
        g[i][9] = 1;
    }
    for (int i = 1; i < 9; ++i) {
        g[0][i] = 1;
        g[9][i] = 1;
    }
    vector<vector<int>> n = g;
    Percolation(&g);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            EXPECT_EQ(g[i][j], n[i][j]);
}
TEST(IslandPercolation, All_die) {
    vector<vector<int>> g(10, vector<int>(10, 0));
    vector<vector<int>> n = g;
    for (int i = 1; i < 9; ++i)
        g[4][i] = 1;
    for (int i = 1; i < 9; ++i)
        g[i][4] = 1;
    Percolation(&g);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            EXPECT_EQ(g[i][j], n[i][j]);
}
TEST(IslandBFS, Correct_work) {
    vector<vector<int>> g(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i)
        g[i][5] = 1;
    g[0][7] = 1;
    g[1][1] = 1;
    g[1][2] = 1;
    g[1][8] = 1;
    g[2][2] = 1;
    g[4][3] = 1;
    g[4][4] = 1;
    g[5][1] = 1;
    g[5][3] = 1;
    g[6][3] = 1;
    g[7][8] = 1;
    g[8][0] = 1;
    g[8][1] = 1;
    g[8][8] = 1;
    g[9][0] = 1;
    g[9][1] = 1;
    vector<vector<int>> n = g;
    n[1][1] = 0;
    n[1][2] = 0;
    n[1][8] = 0;
    n[2][2] = 0;
    n[5][1] = 0;
    n[7][8] = 0;
    n[8][8] = 0;
    BFS(&g);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            EXPECT_EQ(g[i][j], n[i][j]);
}
TEST(IslandBFS, All_live) {
    vector<vector<int>> g(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        g[i][0] = 1;
        g[i][9] = 1;
    }
    for (int i = 1; i < 9; ++i) {
        g[0][i] = 1;
        g[9][i] = 1;
    }
    vector<vector<int>> n = g;
    BFS(&g);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            EXPECT_EQ(g[i][j], n[i][j]);
}
TEST(IslandBFS, All_die) {
    vector<vector<int>> g(10, vector<int>(10, 0));
    vector<vector<int>> n = g;
    for (int i = 1; i < 9; ++i)
        g[4][i] = 1;
    for (int i = 1; i < 9; ++i)
        g[i][4] = 1;
    BFS(&g);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            EXPECT_EQ(g[i][j], n[i][j]);
}


