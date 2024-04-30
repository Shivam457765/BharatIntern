#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

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

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void kruskal(vector<Edge>& edges, int numVertices) {
    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(numVertices);
    vector<Edge> minimumSpanningTree;

    for (const Edge& edge : edges) {
        int rootSrc = uf.find(edge.src);
        int rootDest = uf.find(edge.dest);

        if (rootSrc != rootDest) {
            minimumSpanningTree.push_back(edge);
            uf.unionSets(rootSrc, rootDest);
        }
    }

    // Output the minimum spanning tree
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    // Example usage
    int numVertices = 4;
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 5}
    };

    kruskal(edges, numVertices);

    return 0;
}
