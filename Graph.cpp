#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int V = 4;

// -------------------- ADJACENCY MATRIX --------------------
int adjMatrix[V][V] = {0};

// -------------------- ADJACENCY LIST --------------------
vector<int> adjList[V];

// -------------------- ADD EDGE --------------------
void addEdge(int u, int v) {
    // For undirected graph
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// -------------------- DEGREE (MATRIX) --------------------
int degree(int v) {
    int deg = 0;
    for (int i = 0; i < V; i++) {
        deg += adjMatrix[v][i];
    }
    return deg;
}

// -------------------- DFS PATH --------------------
bool visited[V];

bool dfs(int node, int target) {
    if (node == target) return true;

    visited[node] = true;

    for (int i = 0; i < adjList[node].size(); i++) {
        int next = adjList[node][i];
        if (!visited[next]) {
            if (dfs(next, target))
                return true;
        }
    }
    return false;
}

// -------------------- BFS PATH --------------------
bool bfs(int start, int target) {
    bool vis[V] = {false};
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == target)
            return true;

        for (int i = 0; i < adjList[node].size(); i++) {
            int next = adjList[node][i];
            if (!vis[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

// -------------------- MAIN --------------------
int main() {

    // Creating graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    // -------- MATRIX OUTPUT --------
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // -------- LIST OUTPUT --------
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    // -------- DEGREE --------
    cout << "\nDegrees:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " degree = " << degree(i) << endl;
    }

    // -------- DFS PATH --------
    for (int i = 0; i < V; i++) visited[i] = false;

    int start = 0, target = 3;

    cout << "\nDFS Path from " << start << " to " << target << ": ";
    if (dfs(start, target))
        cout << "Path Exists";
    else
        cout << "No Path";

    // -------- BFS PATH --------
    cout << "\nBFS Path from " << start << " to " << target << ": ";
    if (bfs(start, target))
        cout << "Path Exists";
    else
        cout << "No Path";

    cout << endl;

    return 0;
}