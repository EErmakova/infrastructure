#include <utility>
#include <vector>
#include "dijkstra.h"
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
int main(int argc, char* argv[]) {
    char* path = argv[1];
    argc++;
    argc--;  // fix cpplint error
    printf("\n");
    vector< vector< pair<int, int> > > g = Read_To_Adjacency_List(path);
    vector<int> res = Dijkstra_on_heap(0, g.size(), g);
    cout << "The result of the  Dijkstra_on_heap algorithm" << endl;
    for (int i = 0; i < static_cast<int>(res.size()); ++i)
        cout << res[i] << " ";
    cout << endl;
    vector<int> res1 = Dijkstra_on_AVLTree(0, g.size(), g);
    cout << "The result of the  Dijkstra_on_AVLTree algorithm" << endl;
    for (int i = 0; i < static_cast<int>(res1.size()); ++i)
        cout << res1[i] << " ";
    cout << endl;
}

