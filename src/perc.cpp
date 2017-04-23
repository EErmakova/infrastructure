#include "perc.h"

int Find(vector<int> a, int p) {
    int res = p;
    while (a[res] != res) {
        res = a[res];
    }
    return res;
}
void Union(vector<int>* a, vector<int>* b, int p, int q) {
    int x = Find(*a, p);
    int y = Find(*a, q);
    if ((*b)[x] > (*b)[y]) {
        (*a)[y] = x;
        (*b)[x]++;
    } else {
        (*a)[x] = y;
        (*b)[y]++;
    }
}

bool Percolation(vector<vector<int>> matrix) {
    int M = matrix.size();
    int N = M*M + 2;
    int st = 0;
    int f = M*M + 1;
    vector<int> a(N);
    vector<int> b(N, 1);
    for (int i = 0; i < N; i++)
        a[i] = i;
    for (int i = 0; i < M; ++i)
        if (matrix[0][i] == 1)
            Union(&a, &b, st, i + 1);
    for (int i = 0; i < M - 1; ++i)
        if (matrix[0][i] == 1 && matrix[0][i + 1] == 1)
            Union(&a, &b, i + 1, i + 2);
    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < M - 1; ++j) {
            if (matrix[i][j] == 1 && matrix[i][j + 1])
                Union(&a, &b, i*M + j + 1, i*M + j + 2);
            if (matrix[i][j] == 1 && matrix[i - 1][j])
                Union(&a, &b, i*M + j + 1, (i - 1)*M + j + 1);
        }
        if (matrix[i - 1][M - 1] == 1 && matrix[i][M - 1] == 1)
            Union(&a, &b, (i - 1)*M + M, i*M + M);
    }
    for (int i = 0; i < M; ++i)
        if (matrix[M - 1][i] == 1)
            Union(&a, &b, f, (M - 1)*M + i + 1);
    if (Find(a, st) == Find(a, f))
        return true;
    return false;
}

double Probability(int n, int k) {
    int x;
    int y;
    srand(time(NULL));
    double s = 0;
    double count = 0;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < k; ++i) {
        for (count = 0; !Percolation(g); ++count) {
            x = rand() % n;
            y = rand() % n;
            if (g[x][y] == 1) {
                --count;
                continue;
            }
            g[x][y] = 1;
        }
        s += count / (n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = 0;
    }
    return s / k;
}
