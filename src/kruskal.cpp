#include "spanning_tree.h"
#include "uf.h"
vector<pair<int, pair<int, int>>> Kruskal(vector<vector<pair<int, int>>> g) {
    int n = g.size();
    vector<pair<int, pair<int, int>>> res;
    vector<int> parent(n);
    vector<int> count(n, 1);
    vector<pair<int, int>>::iterator it;
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    vector<pair<int, pair<int, int>>> edges;  // weight - vertex1 - vertex2
    for (int i = 0; i < n; ++i)
        for (it = g[i].begin(); it != g[i].end(); ++it) {
            if ((*it).second == -1)
                continue;
            edges.push_back(make_pair((*it).second, make_pair(i, (*it).first)));
        }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
        int vertex1 = edges[i].second.first;
        int vertex2 = edges[i].second.second;
        int weight = edges[i].first;
        int x = Find(parent, vertex1);
        int y = Find(parent, vertex2);
        if (x != y) {
            res.push_back(edges[i]);
            Union(&parent, &count, vertex1, vertex2);
        }
    }
    return res;
}
