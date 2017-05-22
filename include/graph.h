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
void Write_To_Kruskal_Gv(vector<vector<pair<int, int>>> graph,
    vector<pair<int, pair<int, int>>> spanning_tree) {
    FILE* f = fopen("C:/Users/qq/Kate/Uni/Graphs/Kruskal_spanning_tree.txt", "w");
    if (f == 0)
        throw logic_error("Error! Can`t open the file!");
    fputs("graph { \nedge[color = \"#2EB8E6\"]\n", f);
    int n = spanning_tree.size();
    for (int i = 0; i < n; ++i) {
        int vertex1 = spanning_tree[i].second.first;
        int vertex2 = spanning_tree[i].second.second;
        int weight = spanning_tree[i].first;
        fputc(vertex1 + 48, f);
        fputs("--", f);
        fputc(vertex2 + 48, f);
        fputs("[style = \"bold\", label=\"", f);
        fputc(weight + 48, f);
        fputs("\"]\n", f);
        vector<pair<int, int>>::iterator it = graph[vertex1].begin();
        for (int i = 0; i < static_cast<int>(graph[vertex1].size()); ++i) {
            if (graph[vertex1][i] == (make_pair(vertex2, weight))) {
                graph[vertex1].erase(it);
                continue;
            }
            ++it;
        }
    }
    for (int i = 0; i < static_cast<int>(graph.size()); ++i)
        for (int j = 0; j < static_cast<int>(graph[i].size()); ++i) {
            int vertex1 = i;
            int vertex2 = graph[i][j].first;
            int weight = graph[i][j].second;;
            fputc(vertex1 + 48, f);
            fputs("--", f);
            fputc(vertex2 + 48, f);
            fputs("[color = black, label=\"", f);
            fputc(weight + 48, f);
            fputs("\"]\n", f);
            fputc(vertex1 + 48, f);
            fputs(" [shape = \"rect\", color = black]\n", f);
            fputc(vertex2 + 48, f);
            fputs(" [shape = \"rect\", color = black]\n", f);
        }
    fputs("}\n", f);
    fclose(f);
}
void Write_To_Prim_Gv(vector<vector<int>> graph, vector<pair<int, pair<int, int>>> spanning_tree) {
    FILE* f = fopen("C:/Users/qq/Kate/Uni/Graphs/Prim_spanning_tree.txt", "w");
    if (f == 0)
        throw logic_error("Error! Can`t open the file!");
    fputs("graph { \nedge[color = \"#0DBD1C\"]\n", f);
    int n = spanning_tree.size();
    for (int i = 0; i < n; ++i) {
        int vertex1 = spanning_tree[i].second.first;
        int vertex2 = spanning_tree[i].second.second;
        int weight = spanning_tree[i].first;
        fputc(vertex1 + 48, f);
        fputs("--", f);
        fputc(vertex2 + 48, f);
        fputs("[style = \"bold\", label=\"", f);
        fputc(weight + 48, f);
        fputs("\"]\n", f);
        graph[vertex1][vertex2] = INF;
        graph[vertex2][vertex1] = INF;
    }
    for (int i = 0; i < static_cast<int>(graph.size()); ++i)
        for (int j = 0; j < static_cast<int>(graph[i].size()); ++j)
            if ((graph[i][j] != INF) && (i != j)) {
                fputc(i + 48, f);
                fputs("--", f);
                fputc(j + 48, f);
                fputs("[color = black, label=\"", f);
                fputc(graph[i][j] + 48, f);
                fputs("\"]\n", f);
                fputc(i + 48, f);
                fputs(" [shape = \"rect\", color = black]\n", f);
                fputc(j + 48, f);
                fputs(" [shape = \"rect\", color = black]\n", f);
                graph[j][i] = INF;
            }

    fputs("}\n", f);
    fclose(f);
}
#endif  // INCLUDE_GRAPH_H_
