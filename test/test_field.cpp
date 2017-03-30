#include <gtest/gtest.h>
#include "field.h"

bool Check(int x, int y) {
    int ax = 0;
    int ay = 0;
    int step = 1;
    char* way = FindWay(x, y);
    for (int i = 0; way[i] != '\0'; ++i) {
        if (way[i] == 'N')
            ay += step;
        if (way[i] == 'S')
            ay -= step;
        if (way[i] == 'W')
            ax -= step;
        if (way[i] == 'E')
            ax += step;
        step++;
    }
    return ((x == ax) && (y == ay));
}
TEST(Field, Can_find) {
    for (int x = 0; x < 49; ++x)
        for (int y = 0; y < 49; ++y) {
            bool flag = Check(x, y);
            EXPECT_TRUE(flag);
            flag = Check(-x, y);
            EXPECT_TRUE(flag);
            flag = Check(x, -y);
            EXPECT_TRUE(flag);
            flag = Check(-x, -y);
            EXPECT_TRUE(flag);
        }
}
