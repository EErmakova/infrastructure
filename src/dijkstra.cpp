#include <dijkstra.h>
#include <set>
#include <utility>
#include <vector>
vector<int> Dijkstra(int s, int n, vector<vector<pair<int, int>>> g) {
    if ((s < 0) || (s > n) || (g.empty())) {
        throw std::logic_error("Errors in the start values");
    }
    vector<int> d(n, INF);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto j = 0; j < g[v].size(); ++j) {
            int to = g[v][j].first;
            if (to < 0)
                break;
            int len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    return d;
}

