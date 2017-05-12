#include <cstdlib>
#include <fstream>
#include "graph.h"
int main() {
    printf("KRUSKAL`S ALGORITHM\n");
    printf("ENTER THE PATH TO THE FILE: ");
    char s1[150];
    scanf("%s", s1);
    printf("\n");
    Print_Adjacency_List(s1);
    vector<vector<pair<int, int>>> graph1 = Read_To_Adjacency_List(s1);
    printf("\n");
    vector<pair<int, pair<int, int>>> res_Kruskal = Kruskal(graph1);
    Print_Spanning_Tree(res_Kruskal);
    printf("\n");
    printf("PRIM`S ALGORITHM\n");
    printf("ENTER THE PATH TO THE FILE: ");
    char s2[150];
    scanf("%s", s2);
    printf("\n");
    Print_Adjacency_Matrix(s2);
    vector<vector<int>> graph2 = Read_To_Adjacency_Matrix(s2);
    printf("\n");
    vector<pair<int, pair<int, int>>> res_Prim = Prim(graph2, 1);
    Print_Spanning_Tree(res_Prim);
    return 0;
}
