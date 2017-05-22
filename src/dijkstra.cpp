#include "dijkstra.h"
vector<int> Dijkstra_on_heap(int s, int n, vector<vector<pair<int, int>>> g) {
    if ((s < 0) || (s > n) || (g.empty())) {
        throw logic_error("Errors in the start values");
    }
    vector<int> d(n, INF);
    d[s] = 0;
    Queue_on_heap<pair<int, int>> q;
    q.Push(make_pair(0, s));
    while (!q.IsEmpty()) {
        int v = q.Top().second;
        int cur_d = q.Top().first;
        q.Pop();
        if (cur_d > d[v])
            continue;
        for (int j = 0; j < static_cast<int>(g[v].size()); ++j) {
            int to = g[v][j].first;
            if (to < 0)
                break;
            int len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.Push(make_pair(d[to], to));
            }
        }
    }
    return d;
}
vector<int> Dijkstra_on_AVLTree(int s, int n, vector<vector<pair<int, int>>> g) {
    if ((s < 0) || (s > n) || (g.empty())) {
        throw logic_error("Errors in the start values");
    }
    vector<int> d(n, INF);
    d[s] = 0;
    Queue_on_AVLTree<pair<int, int>> q;
    q.Push(make_pair(0, s));
    while (!q.IsEmpty()) {
        int v = q.Top().second;
        int cur_d = q.Top().first;
        q.Pop();
        if (cur_d > d[v])
            continue;
        for (int j = 0; j < static_cast<int>(g[v].size()); ++j) {
            int to = g[v][j].first;
            if (to < 0)
                break;
            int len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.Push(make_pair(d[to], to));
            }
        }
    }
    return d;
}
