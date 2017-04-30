#include "island.h"

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
void Percolation(vector<vector<int>>* matrix) {
    int M = (*matrix).size();
    int N = M*M + 4;
    int st = 0;
    int left = 1;
    int right = 2;
    int fin = M*M + 3;
    vector<int> a(N);
    vector<int> b(N, 1);
    for (int i = 0; i < N; i++)
        a[i] = i;
    for (int i = 0; i < M; ++i)
        if ((*matrix)[0][i] == 1)
            Union(&a, &b, st, i + 3);
    for (int i = 0; i < M; ++i)
        if ((*matrix)[i][0] == 1)
            Union(&a, &b, left, i*M + 3);
    for (int i = 0; i < M; ++i)
        if ((*matrix)[M-1][i] == 1)
            Union(&a, &b, right, i*M + (M-1) + 3);
    for (int i = 0; i < M - 1; ++i)
        if ((*matrix)[0][i] == 1 && (*matrix)[0][i + 1] == 1)
            Union(&a, &b, i + 3, i + 4);
    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < M - 1; ++j) {
            if ((*matrix)[i][j] == 1 && (*matrix)[i][j + 1])
                Union(&a, &b, i*M + j + 3, i*M + j + 4);
            if ((*matrix)[i][j] == 1 && (*matrix)[i - 1][j])
                Union(&a, &b, i*M + j + 3, (i - 1)*M + j + 3);
        }
        if ((*matrix)[i - 1][M - 1] == 1 && (*matrix)[i][M - 1] == 1)
            Union(&a, &b, (i - 1)*M + M, i*M + M);
    }
    for (int i = 0; i < M; ++i)
        if ((*matrix)[M - 1][i] == 1)
            Union(&a, &b, fin, (M - 1)*M + i + 4);
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j) {
            int x = Find(a, i*M + 3 + j);
            int s = Find(a, st);
            int l = Find(a, left);
            int r = Find(a, right);
            int f = Find(a, fin);
            if (((x != s) && (x != l) && (x != r) && (x != f)) && ((*matrix)[i][j] == 1))
                (*matrix)[i][j] = 0;
        }
}
void BFS_set(vector<vector<int>> matrix, vector<vector<int>>* field, coord v) {
    int m = matrix.size();
    queue<coord> q;
    q.push(v);
    (*field)[v.str][v.col] = 1;
    while (!q.empty()) {
        coord vertex = q.front();
        q.pop();
        if (vertex.str > 0) {
            if ((matrix[vertex.str - 1][vertex.col] == 1) &&
                ((*field)[vertex.str - 1][vertex.col] == INF)) {
                coord* tmp = new coord;
                tmp->str = (vertex.str - 1);
                tmp->col = (vertex.col);
                q.push(*tmp);
                (*field)[vertex.str - 1][vertex.col] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }
        if (vertex.str < (m - 1)) {
            if ((matrix[vertex.str + 1][vertex.col] == 1) &&
                ((*field)[vertex.str + 1][vertex.col] == INF)) {
                coord* tmp = new coord;
                tmp->str = (vertex.str + 1);
                tmp->col = (vertex.col);
                q.push(*tmp);
                (*field)[vertex.str + 1][vertex.col] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }
        if (vertex.col > 0) {
            if ((matrix[vertex.str][vertex.col - 1] == 1) &&
                ((*field)[vertex.str][vertex.col - 1] == INF)) {
                coord* tmp = new coord;
                tmp->str = (vertex.str);
                tmp->col = (vertex.col - 1);
                q.push(*tmp);
                (*field)[vertex.str][vertex.col - 1] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }
        if (vertex.col < m - 1) {
            if ((matrix[vertex.str][vertex.col + 1] == 1) &&
                ((*field)[vertex.str][vertex.col + 1] == INF)) {
                coord* tmp = new coord;
                tmp->str = (vertex.str);
                tmp->col = (vertex.col + 1);
                q.push(*tmp);
                (*field)[vertex.str][vertex.col + 1] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }
    }
}

void BFS(vector<vector<int>>* matrix) {
    int m = (*matrix).size();
    vector<vector<int>> field(m, vector<int>(m, INF));
    coord v;
    v.col = 0;
    for (v.str = 0; v.str < m; ++v.str)
        if (((*matrix)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            BFS_set((*matrix), &field, v);
    v.col = m - 1;
    for (v.str = 0; v.str < m; ++v.str)
        if (((*matrix)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            BFS_set((*matrix), &field, v);
    v.str = 0;
    for (v.col = 0; v.col < m; ++v.col)
        if (((*matrix)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            BFS_set((*matrix), &field, v);
    v.str = m- 1;
    for (v.col = 0; v.col < m; ++v.col)
        if (((*matrix)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            BFS_set((*matrix), &field, v);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if (field[i][j] == INF)
                (*matrix)[i][j] = 0;
}


