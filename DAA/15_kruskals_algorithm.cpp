#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;

    // Custom comparison for sorting edges
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Union-Find data structure
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the root of the set to which x belongs
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union of two sets
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

// Kruskal's algorithm to find the minimum cost spanning tree
void kruskal(const vector<Edge>& edges, int numVertices) {
    // Sort edges in non-decreasing order of their weights
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end());

    UnionFind uf(numVertices);
    vector<Edge> minimumSpanningTree;

    for (const Edge& edge : sortedEdges) {
        int rootSource = uf.find(edge.source);
        int rootDest = uf.find(edge.destination);

        // If including this edge doesn't create a cycle, add it to the MST
        if (rootSource != rootDest) {
            minimumSpanningTree.push_back(edge);
            uf.unionSets(rootSource, rootDest);
        }
    }

    // Output the minimum spanning tree
    cout << "Minimum Cost Spanning Tree:\n";
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.source << " - " << edge.destination << " : " << edge.weight << "\n";
    }
}

int main() {
    // Example usage
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<Edge> edges;
    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < numEdges; ++i) {
        Edge edge;
        cin >> edge.source >> edge.destination >> edge.weight;
        edges.push_back(edge);
    }

    kruskal(edges, numVertices);

    return 0;
}
