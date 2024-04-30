#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Structure to represent an edge in the graph
struct Edge {
    int destination, weight;

    // Custom comparison for priority queue
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

// Prim's algorithm to find the minimum cost spanning tree
void prim(const vector<vector<Edge>>& graph, int numVertices) {
    vector<int> parent(numVertices, -1);  // To store the parent of each vertex in the MST
    vector<int> key(numVertices, INF);    // To store the key (minimum edge weight) of each vertex
    vector<bool> inMST(numVertices, false);  // To track whether a vertex is in the MST

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // Start from the first vertex
    int startVertex = 0;
    pq.push({startVertex, 0});
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().destination;
        pq.pop();

        // Skip if the vertex is already in the MST
        if (inMST[u]) {
            continue;
        }

        inMST[u] = true;

        // Explore neighbors of the current vertex
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // If v is not in the MST and the weight of the edge is smaller than the current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }

    // Output the minimum spanning tree
    cout << "Minimum Cost Spanning Tree:\n";
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << " : " << key[i] << "\n";
    }
}

int main() {
    // Example usage
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    // Input the graph
    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < numEdges; ++i) {
        Edge edge;
        cin >> edge.destination >> edge.weight;
        graph[edge.destination].push_back({0, edge.weight});  // Assuming the graph is undirected
        graph[0].push_back({edge.destination, edge.weight});
    }

    prim(graph, numVertices);

    return 0;
}
