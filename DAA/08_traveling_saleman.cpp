#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to find the nearest neighbor for a given city
int findNearestNeighbor(int currentCity, const vector<vector<int>>& distances, vector<bool>& visited) {
    int nearestNeighbor = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < distances.size(); ++i) {
        if (!visited[i] && distances[currentCity][i] < minDistance) {
            minDistance = distances[currentCity][i];
            nearestNeighbor = i;
        }
    }

    return nearestNeighbor;
}

// Function to solve TSP using the nearest neighbor algorithm
void solveTSP(const vector<vector<int>>& distances, vector<int>& tour) {
    int numCities = distances.size();

    // Start with the first city as the current city
    int currentCity = 0;

    // Mark the first city as visited
    vector<bool> visited(numCities, false);
    visited[currentCity] = true;

    // Iterate through the remaining cities
    for (int i = 1; i < numCities; ++i) {
        // Find the nearest neighbor
        int nearestNeighbor = findNearestNeighbor(currentCity, distances, visited);

        // Move to the nearest neighbor
        tour.push_back(nearestNeighbor);
        visited[nearestNeighbor] = true;
        currentCity = nearestNeighbor;
    }

    // Return to the starting city to complete the tour
    tour.push_back(tour[0]);
}

int main() {
    // Example distances between cities
    vector<vector<int>> distances = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Vector to store the tour
    vector<int> tour;

    // Solve TSP
    solveTSP(distances, tour);

    // Print the tour
    cout << "Optimal Tour: ";
    for (int city : tour) {
        cout << city << " ";
    }

    return 0;
}