#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Structure to represent a vertex and its distance from the source
struct VertexDistance {
    int vertex;
    int distance;

    // Define a custom comparison for the priority queue
    bool operator>(const VertexDistance& other) const {
        return distance > other.distance;
    }
};

// Dijkstra's algorithm to find the shortest paths from a given source vertex
void dijkstra(const vector<vector<Edge>>& graph, int source, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    distances[source] = 0;

    priority_queue<VertexDistance, vector<VertexDistance>, greater<VertexDistance>> pq;
    pq.push({source, 0});

    while (!pq.empty()) {
        VertexDistance current = pq.top();
        pq.pop();

        int u = current.vertex;
        int dist = current.distance;

        // If the distance to u is already smaller than the current distance, skip
        if (dist > distances[u]) {
            continue;
        }

        // Relaxation step
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (dist + weight < distances[v]) {
                distances[v] = dist + weight;
                pq.push({v, distances[v]});
            }
        }
    }
}

int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    // Input the graph
    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});  // Assuming the graph is undirected
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    // Perform Dijkstra's algorithm
    vector<int> distances;
    dijkstra(graph, source, distances);

    // Output the shortest distances
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To vertex " << i << ": " << distances[i] << "\n";
    }

    return 0;
}
