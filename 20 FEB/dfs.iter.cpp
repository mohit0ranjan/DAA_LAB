#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs_iterative(vector<vector<int>> &adj, int start, vector<bool> &visited) {
    stack<int> s;
    s.push(start);
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int i = adj[node].size() - 1; i >= 0; i--) {
                if (!visited[adj[node][i]]) {
                    s.push(adj[node][i]);
                }
            }
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {5};
    adj[4] = {8};
    adj[5] = {2};

    vector<bool> visited(n, false);
    dfs_iterative(adj, 0, visited);

    return 0;
}
