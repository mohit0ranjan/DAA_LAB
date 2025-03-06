#include <iostream>
#include <vector>

using namespace std;

#define V 5
#define INF 99999

int findMin(vector<int>& key, vector<bool>& visited) {
    int min = INF, index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void primMST(vector<vector<int>>& graph) {
    vector<int> parent(V, -1);
    vector<int> key(V, INF);
    vector<bool> visited(V, false);

    key[0] = 0; 

    for (int count = 0; count < V - 1; count++) {
        int u = findMin(key, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {2, 2, 0, 6, 8},
        {2, 5, 3, 8, 5},
        {0, 3, 8, 0, 7},
        {6, 8, 9, 9, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
