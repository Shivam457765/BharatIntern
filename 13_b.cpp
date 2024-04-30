#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
    double valueToWeightRatio;

    // Custom comparison for sorting based on value-to-weight ratio
    bool operator>(const Item& other) const {
        return valueToWeightRatio > other.valueToWeightRatio;
    }
};

// Function to solve the 0/1 Knapsack Problem using a greedy approach
int knapsackGreedy(const vector<Item>& items, int capacity) {
    int n = items.size();
    int totalValue = 0;

    // Sort items based on their value-to-weight ratio in descending order
    vector<Item> sortedItems(items);
    sort(sortedItems.begin(), sortedItems.end(), greater<Item>());

    // Initialize an array to track whether an item is included in the knapsack
    vector<bool> included(n, false);

    // Greedy by value-to-weight ratio
    for (int i = 0; i < n; ++i) {
        if (capacity >= sortedItems[i].weight) {
            included[i] = true;
            totalValue += sortedItems[i].value;
            capacity -= sortedItems[i].weight;
        }
    }

    // Output the selected items
    cout << "Selected items:\n";
    for (int i = 0; i < n; ++i) {
        if (included[i]) {
            cout << "Item " << i + 1 << " - Weight: " << items[i].weight << ", Value: " << items[i].value << "\n";
        }
    }

    return totalValue;
}

int main() {
    // Example usage
    int n;  // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    // Input weights and values of each item
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
        items[i].valueToWeightRatio = static_cast<double>(items[i].value) / items[i].weight;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    // Call the knapsackGreedy function
    int totalValue = knapsackGreedy(items, capacity);

    // Output the total value
    cout << "Total value that can be obtained: " << totalValue << endl;

    return 0;
}
