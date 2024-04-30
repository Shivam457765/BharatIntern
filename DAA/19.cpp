#include <iostream>
#include <vector>

using namespace std;

class HamiltonianCycle {
private:
    int V;
    vector<vector<int>> graph;
    vector<int> path;

public:
    HamiltonianCycle(int vertices) : V(vertices), graph(vertices, vector<int>(vertices, 0)), path(vertices, -1) {}

    void addEdge(int u, int v) {
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    bool is_valid(int v, int pos) {
        if (!graph[path[pos - 1]][v])
            return false;

        for (int i = 0; i < pos; ++i)
            if (path[i] == v)
                return false;

        return true;
    }

    void hamiltonian_cycle_util(int pos) {
        if (pos == V) {
            // Print Hamiltonian cycle
            for (int i = 0; i < V; ++i)
                cout << path[i] << " ";
            cout << path[0] << endl;
            return;
        }

        for (int v = 1; v < V; ++v) {
            if (is_valid(v, pos)) {
                path[pos] = v;
                hamiltonian_cycle_util(pos + 1);
                path[pos] = -1; // backtrack
            }
        }
    }

    void find_hamiltonian_cycles() {
        path[0] = 0; // Start from the first vertex
        hamiltonian_cycle_util(1);
    }
};

int main() {
    HamiltonianCycle hc(5); // Replace 5 with the number of vertices in your graph

    // Add edges to the graph
    hc.addEdge(0, 1);
    hc.addEdge(0, 3);
    hc.addEdge(1, 2);
    hc.addEdge(1, 3);
    hc.addEdge(1, 4);
    hc.addEdge(2, 4);
    hc.addEdge(3, 4);

    cout << "Hamiltonian Cycles:" << endl;
    hc.find_hamiltonian_cycles();

    return 0;
}
