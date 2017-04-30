#include "island.h"
int main() {
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
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
            cout << g[i][j] << " ";
        cout << endl;
    }
    vector<vector<int>> n = g;
    Percolation(&g);
    BFS(&n);
    bool flag = true;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (g[i][j] != n[i][j])
                flag = false;
    cout << "Both function works equally?: ";
    if (flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "The result of work of the functions:" << endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
            cout << n[i][j] << " ";
        cout << endl;
    }
}
