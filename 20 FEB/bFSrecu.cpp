#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs_recursive(vector<vector<int>> &adj, queue<int> &q, vector<bool> &visited) {
    if (q.empty()) return;

    int node = q.front();
    q.pop();
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }

    bfs_recursive(adj, q, visited);
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    bfs_recursive(adj, q, visited);

    return 0;
}
