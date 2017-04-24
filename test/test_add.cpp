#include <gtest/gtest.h>
#include "island.h"

TEST(IslandPercolation, Correct_work) {
	vector<vector<int>> g(5, vector<int>(5,0));
	g[0][4] = 1;
	g[1][1] = 1;
	g[2][2] = 1;
	g[2][3] = 1;
	g[3][3] = 1;
	g[4][0] = 1;
	Percolation(&g);
	EXPECT_EQ(g[1][1], 0);
	EXPECT_EQ(g[2][2], 0);
	EXPECT_EQ(g[2][3], 0);
	EXPECT_EQ(g[3][3], 0);
	EXPECT_EQ(g[0][4], 1);
	EXPECT_EQ(g[4][0], 1);
}
