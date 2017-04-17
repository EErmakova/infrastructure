#include "massive.h"
int main() {
    const int n = 5;
    const int m = 1;
    int a[5] = { 1, -2, 3, -4, 2 };
    cout << "Initial massive" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    int* res = Multiply(a, n);
    cout << "Massive created by the function" << endl;
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl << endl;
    int uno[1] = { 123 };
    cout << "Initial massive" << endl;
    cout << uno[0] << endl;
    res = Multiply(uno, m);
    cout << "Massive created by the function" << endl;
    for (int i = 0; i < m; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
