#include "field.h"
char* FindWay(int x, int y) {
    char*  way = new char[2*abs(x) + 2*abs(y) +1];
    int ax = 0;
    int ay = 0;
    int step = 1;
    if (x < 0) {
        while (ax - step > x) {
            ax -= step;
            way[step - 1] = 'W';
            ++step;
        }
        while (ax != x) {
            ax += step;
            way[step - 1] = 'E';
            ++step;
            ax -= step;
            way[step - 1] = 'W';
            ++step;
        }
    }
    if (x > 0) {
        while (ax + step < x) {
            ax += step;
            way[step - 1] = 'E';
            ++step;
        }
        while (ax != x) {
            ax -= step;
            way[step - 1] = 'W';
            ++step;
            ax += step;
            way[step - 1] = 'E';
            ++step;
        }
    }
    if (y < 0) {
        while (ay - step > y) {
            ay -= step;
            way[step - 1] = 'S';
            ++step;
        }
        while (ay != y) {
            ay += step;
            way[step - 1] = 'N';
            ++step;
            ay -= step;
            way[step - 1] = 'S';
            ++step;
        }
    }
    if (y > 0) {
        while (ay + step > y) {
            ay += step;
            way[step - 1] = 'N';
            ++step;
        }
        while (ay != y) {
            ay -= step;
            way[step - 1] = 'S';
            ++step;
            ay += step;
            way[step - 1] = 'N';
            ++step;
        }
    }
    way[step - 1] = '\0';
    return way;
}

