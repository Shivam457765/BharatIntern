#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double ratio; // value-to-weight ratio

    Item(int w, int v) : weight(w), value(v), ratio(static_cast<double>(v) / w) {}
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.ratio > item2.ratio;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    // Sort items based on value-to-weight ratio in non-increasing order
    std::sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const Item& item : items) {
        if (remainingCapacity == 0) {
            break;
        }

        int amountTaken = std::min(remainingCapacity, item.weight);
        totalValue += amountTaken * item.ratio;
        remainingCapacity -= amountTaken;
    }

    return totalValue;
}

int main() {
    int capacity;
    std::cout << "Enter the capacity of the knapsack: ";
    std::cin >> capacity;

    int n;
    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::vector<Item> items;

    for (int i = 0; i < n; ++i) {
        int weight, value;
        std::cout << "Enter weight and value for item " << i + 1 << ": ";
        std::cin >> weight >> value;
        items.emplace_back(weight, value);
    }

    double result = fractionalKnapsack(capacity, items);

    std::cout << "Maximum value that can be obtained: " << result << std::endl;

    return 0;
}
