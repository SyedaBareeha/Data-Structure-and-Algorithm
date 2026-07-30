#include <iostream>
#include <vector>
#include "file.h"
using namespace std;

void DFS(vector<vector<int>> &graph, int start, int V) {
    vector<bool> visited(V, false);

    push(start);

    while (!isEmpty()) {
        int node = peek();
        pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;

            // push neighbors
            for (int i = graph[node].size() - 1; i >= 0; i--) {
                int adj = graph[node][i];
                if (!visited[adj]) {
                    push(adj);
                }
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph(V);

    // Example graph
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    DFS(graph, 0, V);

    return 0;
}