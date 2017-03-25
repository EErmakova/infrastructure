#include "massive.h"
int* Multiply(int* a, int n) {
    int* result = new int[n];
    if (n == 0)
        std::logic_error("Enter a non-empty massive");
    if (n == 1) {
        result[0] = 1;
        return result;
    }

    int* tmp = new int[n - 1];
    int loc = 1;
    for (int i = 0; i < n - 1; ++i) {
        loc *= a[i];
        tmp[i] = loc;
    }
    int r = 1;
    for (int j = n - 1; j > 0; --j) {
        result[j] = tmp[j - 1] * r;
        r *= a[j];
    }
    result[0] = r;
    delete[] tmp;
    return result;
}
