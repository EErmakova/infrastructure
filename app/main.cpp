#include <iostream>
#include "field.h"
using std::cout;
using std::endl;
int main() {
    char* way = FindWay(5, 0);
    char* way2 = FindWay(-4, 5);
    cout << way << endl;
    cout << way2 << endl;
    return 0;
}
