#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> &graph, int startNode, vector<bool> &visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int totalNodes = 6;
    vector<vector<int>> graph(totalNodes);
    
    graph[0] = {1, 2};
    graph[1] = {0, 5, 7};
    graph[2] = {0, 8};
    graph[3] = {5};
    graph[4] = {5};
    graph[5] = {5};

    vector<bool> visited(totalNodes, false);
    bfs(graph, 0, visited);

    return 0;
}