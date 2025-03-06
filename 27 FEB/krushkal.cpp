#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int start, end, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] != node)
            parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionSets(int node1, int node2) {
        int root1 = findParent(node1);
        int root2 = findParent(node2);
        if (root1 != root2) {
            if (rank[root1] > rank[root2])
                parent[root2] = root1;
            else if (rank[root1] < rank[root2])
                parent[root1] = root2;
            else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

int kruskalAlgorithm(int totalNodes, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet ds(totalNodes);
    int totalWeight = 0, selectedEdges = 0;

    for (Edge edge : edges) {
        if (ds.findParent(edge.start) != ds.findParent(edge.end)) {
            ds.unionSets(edge.start, edge.end);
            totalWeight += edge.weight;
            selectedEdges++;
            if (selectedEdges == totalNodes - 1) break;
        }
    }
    return totalWeight;
}

int main() {
    int totalNodes = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    cout << "Minimum Spanning Tree Cost: " << kruskalAlgorithm(totalNodes, edges) << endl;
    return 0;
}
