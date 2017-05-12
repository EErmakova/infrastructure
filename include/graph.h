#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_
#include "spanning_tree.h"
#include <stdio.h>
#include <stdexcept>
using std::logic_error;
vector<vector<pair<int, int>>> Read_To_Adjacency_List(char* name) {
    FILE* f = fopen(name, "r");
    if (f == 0)
        throw logic_error("Error! Can`t open the file!");
    vector<vector<pair<int, int>>> graph;
    int ch = 0;
    vector<pair<int, int>>* v = new vector<pair<int, int>>;
    ch = fgetc(f);
    while (ch != ':')
        ch = fgetc(f);
    while ((ch = fgetc(f)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                if ((*v).size() == 0)
                    (*v).push_back(make_pair(-1, -1));

                graph.push_back(*v);
                v = new vector<pair<int, int>>;
                while (ch != ':')
                    ch = fgetc(f);
            } else {
                int vertex = ch;
                ch = fgetc(f);
                if ((ch = fgetc(f)) == '\n')
                    throw logic_error("Error! Incorrect list!");
                (*v).push_back(make_pair(vertex - 48, ch - 48));
            }
        }
    }
    graph.push_back(*v);
    fclose(f);
    return graph;
}
void Print_Adjacency_List(char* name) {
    FILE* f = fopen(name, "r");
    if (f == 0)
        throw logic_error("Error! Can`t open the file!");
    printf("GRAPH FROM THE FILE:\n");
    int ch = 0;
    ch = fgetc(f);
    while (ch != ':')
        ch = fgetc(f);
    int i = 0;
    printf("%d: ", i);
    ++i;
    while ((ch = fgetc(f)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                printf("\n");
                while (ch != ':')
                    ch = fgetc(f);
                printf("%d: ", i);
                ++i;
            } else {
                printf("%-5d", ch - 48);
                ch = fgetc(f);
                if ((ch = fgetc(f)) == '\n')
                    throw logic_error("Error! Incorrect list!");
                printf("%-5d", ch - 48);
            }
        }
    }
    printf("\n");
}
void Print_Adjacency_Matrix(char* name) {
    FILE* f = fopen(name, "r");
    if (f == 0)
        throw logic_error("Error! Can`t open the file!");
    printf("GRAPH FROM THE FILE:\n");
    int ch = 0;
    while ((ch = fgetc(f)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                printf("\n");
            } else {
                if (ch == '-')
                    printf("%-9s", "-");
                else
                    printf("%-9d", ch - 48);
            }
        }
    }
    printf("\n");
}
vector<vector<int>> Read_To_Adjacency_Matrix(char* name) {
    FILE* f = fopen(name, "r");
    if (f == 0)
        throw logic_error("Error! Can`t open the file!");
    vector<vector<int>> graph;
    int ch = 0;
    vector<int>* v = new vector<int>;
    while ((ch = fgetc(f)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                graph.push_back(*v);
                v = new vector<int>;
            } else {
                if (ch == '-')
                    v->push_back(INF);
                else
                    v->push_back(ch - 48);
            }
        }
    }
    graph.push_back(*v);
    fclose(f);
    return graph;
}
void Print_Spanning_Tree(vector<pair<int, pair<int, int>>> graph) {
    int n = graph.size();
    printf("THE GENERATED SPANNING TREE:\n");
    printf("%-9s", "vertex 1 ");
    printf("| ");
    printf("%-9s", "vertex 2 ");
    printf("| ");
    printf("%-9s", "weight");
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%-9d| ", graph[i].second.first);
        printf("%-9d| ", graph[i].second.second);
        printf("%-6d\n", graph[i].first);
    }
    printf("\n");
}
#endif  // INCLUDE_GRAPH_H_
