#include "spanning_tree.h"
#include "priority_queue.h"
#include <stdio.h>
using std::min;
using std::max;
vector<pair<int, pair<int, int>>> Prim(vector<vector<int>> g, int st) {
    int n = g.size();
    vector<pair<int, pair<int, int>>> res;
    if (n == 0)
        return res;
    vector<int> min_e(n, INF), sel_e(n, -1);
    min_e[st] = 0;
    Queue_on_heap<pair<int, int>> q;
    vector<bool> used(n + 1, false);
    q.Push(make_pair(min_e[st], st));
    for (int i = 0; i < n; ++i) {
        if (q.IsEmpty())
            throw logic_error("No MST");
        int vertex = q.Top().second;
        q.Pop();
        used[vertex] = true;
        if (sel_e[vertex] != -1) {
            int mi = min(sel_e[vertex], vertex);
            int ma = max(sel_e[vertex], vertex);
            res.push_back(make_pair(min_e[vertex], make_pair(mi, ma)));
        }
        for (size_t j = 0; j < g[vertex].size(); ++j) {
            int to = j;
            int cost = g[vertex][j];
            if (cost < min_e[to] && !used[to]) {
                q.Erase(make_pair(min_e[to], to));
                min_e[to] = cost;
                sel_e[to] = vertex;
                q.Push(make_pair(min_e[to], to));
            }
        }
    }
    return res;
}
