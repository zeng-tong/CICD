//
// Created by tong zeng on 2018/6/27.
//

#include <iostream>
#include <vector>
using namespace std;

bool findCircle(vector<vector<int> >& graph, vector<bool> visited, int v, int myParent) {
    if (visited[v]) return true;
    visited[v] = true;
    for(int i = 0; i < graph[v].size(); ++i) {
        if (graph[v][i] == myParent) continue;
        if (findCircle(graph, visited, graph[v][i], v)) return true;
    }
    return false;
}

int main(){
    vector<vector<int> > graph = {{1, 2}, {3, 4, 5}, {0, 5}, {1}, {1}, {1,2}};
    vector<bool> visited(5, false);
    cout << findCircle(graph, visited, 0, -1) << endl;
    return 0;
}