#include <iostream>
#include <vector>

using namespace std;

void dfs_recursive(vector<vector<int>> &adj, int node, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs_recursive(adj, neighbor, visited);
        }
    }
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
    dfs_recursive(adj, 0, visited);

    return 0;
}
