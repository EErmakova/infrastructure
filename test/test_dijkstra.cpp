#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "dijkstra.h"
/*on Heap*/
TEST(DIJKSTRAonHeap, Can_find_way) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9) },
    { make_pair(1, 3), make_pair(3, 2) },
    { make_pair(4, 7) },
    { make_pair(-1, -1) } };
    vector<int> res = Dijkstra_on_heap(0, g.size(), g);

    EXPECT_EQ(res[1], 11);
    EXPECT_EQ(res[2], 8);
    EXPECT_EQ(res[3], 10);
    EXPECT_EQ(res[4], 17);
}
TEST(DIJKSTRAonHeap, Cant_use_negative_start) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9) },
    { make_pair(1, 3), make_pair(3, 2) },
    { make_pair(-1, -1) } };
    EXPECT_ANY_THROW(Dijkstra_on_heap(-10, static_cast<int>(g.size()), g));
}
TEST(DIJKSTRAonHeap, Cant_use_too_big_start) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9) },
    { make_pair(1, 3), make_pair(3, 2) },
    { make_pair(-1, -1) } };
    EXPECT_ANY_THROW(Dijkstra_on_heap(10, static_cast<int>(g.size()), g));
}
TEST(DIJKSTRAonHeap, Cant_use_empty_graph) {
    vector< vector< pair<int, int> > > g;
    EXPECT_ANY_THROW(Dijkstra_on_heap(0, static_cast<int>(g.size()), g));
}
TEST(DIJKSTRAonHeap, Can_use_one_vertex_graph) {
    vector< vector< pair<int, int> > > g(1);
    vector<int> res = Dijkstra_on_heap(0, static_cast<int>(g.size()), g);
    EXPECT_EQ(res[0], 0);
}
TEST(DIJKSTRAonHeap, Can_use_disconnected_graph) {
    vector < vector < pair<int, int> > > g(3);
    g[0].push_back(pair<int, int>(2, 5));
    vector <int> res = Dijkstra_on_heap(0, static_cast<int>(g.size()), g);
    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], INF);
    EXPECT_EQ(res[2], 5);
}
TEST(DIJKSTRAonHeap, Can_find_min_way) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9), make_pair(4, 20) },
    { make_pair(3, 15), make_pair(1, 3) },
    { make_pair(4, 7) },
    { make_pair(-1, -1) } };
    vector<int> res = Dijkstra_on_heap(0, static_cast<int>(g.size()), g);
    EXPECT_EQ(res[3], 20);
    EXPECT_EQ(res[4], 27);
}
/*on AVL-tree*/
TEST(DIJKSTRAonAVLTree, Can_find_way) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9) },
    { make_pair(1, 3), make_pair(3, 2) },
    { make_pair(4, 7) },
    { make_pair(-1, -1) } };
    vector<int> res = Dijkstra_on_AVLTree(0, g.size(), g);

    EXPECT_EQ(res[1], 11);
    EXPECT_EQ(res[2], 8);
    EXPECT_EQ(res[3], 10);
    EXPECT_EQ(res[4], 17);
}
TEST(DIJKSTRAonAVLTree, Cant_use_negative_start) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9) },
    { make_pair(1, 3), make_pair(3, 2) },
    { make_pair(-1, -1) } };
    EXPECT_ANY_THROW(Dijkstra_on_AVLTree(-10, static_cast<int>(g.size()), g));
}
TEST(DIJKSTRAonAVLTree, Cant_use_too_big_start) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9) },
    { make_pair(1, 3), make_pair(3, 2) },
    { make_pair(-1, -1) } };
    EXPECT_ANY_THROW(Dijkstra_on_AVLTree(10, static_cast<int>(g.size()), g));
}
TEST(DIJKSTRAonAVLTree, Cant_use_empty_graph) {
    vector< vector< pair<int, int> > > g;
    EXPECT_ANY_THROW(Dijkstra_on_AVLTree(0, static_cast<int>(g.size()), g));
}
TEST(DIJKSTRAonAVLTree, Can_use_one_vertex_graph) {
    vector< vector< pair<int, int> > > g(1);
    vector<int> res = Dijkstra_on_AVLTree(0, static_cast<int>(g.size()), g);
    EXPECT_EQ(res[0], 0);
}
TEST(DIJKSTRAonAVLTree, Can_use_disconnected_graph) {
    vector < vector < pair<int, int> > > g(3);
    g[0].push_back(pair<int, int>(2, 5));
    vector <int> res = Dijkstra_on_AVLTree(0, static_cast<int>(g.size()), g);
    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], INF);
    EXPECT_EQ(res[2], 5);
}
TEST(DIJKSTRAonAVLTree, Can_find_min_way) {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9), make_pair(4, 20) },
    { make_pair(3, 15), make_pair(1, 3) },
    { make_pair(4, 7) },
    { make_pair(-1, -1) } };
    vector<int> res = Dijkstra_on_AVLTree(0, static_cast<int>(g.size()), g);
    EXPECT_EQ(res[3], 20);
    EXPECT_EQ(res[4], 27);
}
