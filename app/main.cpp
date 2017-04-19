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
    vector<int> res = Dijkstra_on_heap(0, g.size(), g);
    cout << "The result of the  Dijkstra_on_heap algorithm" << endl;
    for (int i = 0; i < static_cast<int>(res.size()); ++i)
        cout << res[i] << " ";
    cout << endl;
    vector<int> res1 = Dijkstra_on_AVLTree(0, g.size(), g);
    cout << "The result of the  Dijkstra_on_AVLTree algorithm" << endl;
    for (int i = 0; i < static_cast<int>(res1.size()); ++i)
        cout << res1[i] << " ";
    cout << endl;
}
