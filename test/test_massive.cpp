#include <gtest/gtest.h>
#include "field.h"

TEST(Field, Find_on_OX) {
   char* way = FindWay(4,0);
   char* res = "WEWEWEWE";
   for (int i = 0; i < 8; ++i)
       EXPECT_EQ(way[i], res[i]); 

}
TEST(Field, Find_on_minus_OX) {
    char* way = FindWay(-4, 0);
    char* res = "EWEWEWEW";
    for (int i = 0; i < 8; ++i)
        EXPECT_EQ(way[i], res[i]);
}
TEST(Field, Find_on_OY) {
    char* way = FindWay(0, 5);
    char* res = "SNSNSNSN";
    for (int i = 0; i < 8; ++i)
        EXPECT_EQ(way[i], res[i]);
}
TEST(Field, Find_on_minus_OY) {
    char* way = FindWay(0, -5);
    char* res = "NSNSNSNSNS";
    for (int i = 0; i < 8; ++i)
        EXPECT_EQ(way[i], res[i]);
}