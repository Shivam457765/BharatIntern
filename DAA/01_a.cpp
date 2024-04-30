#include <iostream>
#include <vector>

// Recursive linear search function
int linearSearch(const std::vector<int>& arr, int target, int index) {
    if (index < arr.size()) {
        if (arr[index] == target) {
            return index;  // Element found
        } else {
            // Search in the rest of the array
            return linearSearch(arr, target, index + 1);
        }
    }

    return -1;  // Element not found
}

int main() {
    // Example usage
    std::vector<int> array = {10, 5, 8, 2, 7, 1, 3};
    int target;

    std::cout << "Enter the number to search for: ";
    std::cin >> target;

    int result = linearSearch(array, target, 0);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
