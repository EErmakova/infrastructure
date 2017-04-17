#include <utility>
#include <vector>
#include "dijkstra.h"
int main() {
    vector< vector< pair<int, int> > > g =
    { { make_pair(2, 8) },
    { make_pair(3, 9) },
    { make_pair(3, 2), make_pair(1 , 3) },
    { make_pair(4, 7) },
    { make_pair(-1, -1) } };
    vector<int> res = Dijkstra(0, g.size(), g);
    for (int i = 0; i < static_cast<int>(res.size()); ++i)
        cout << res[i] << " ";
    cout << endl;
    vector< vector< pair<int, int> > > n =
    { { make_pair(2, 8) },
    { make_pair(3, 9), make_pair(4, 20) },
    { make_pair(3, 15), make_pair(1, 3) },
    { make_pair(4, 7) },
    { make_pair(-1, -1) } };
    vector<int> res1 = Dijkstra(0, n.size(), n);
    for (int i = 0; i < static_cast<int>(res1.size()); ++i)
        cout << res1[i] << " ";
    cout << endl;
}
