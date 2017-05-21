#include "sets.h"
vector<int> Sets(int n, vector<pair<int, int>> pairs) {
    vector<int> res(n);
    int size = static_cast<int>(pairs.size());
    for (int i = 0; i < n; ++i)
        res[i] = i;
    for (int i = 0; i < n - 1; ++i)
        if (res[i] == i) {
            for (int j = i + 1; j < n; ++j)
                if (res[j] == j) {
                    bool flag = true;
                    for (int s = 0; s < size; ++s)
                        if (((res[pairs[s].first] == i) && (res[pairs[s].second] == j))
                            || ((res[pairs[s].first] == j) && (res[pairs[s].second] == i)))
                            flag = false;
                    if (flag)
                        res[j] = i;
                }
        }
    return res;
}
