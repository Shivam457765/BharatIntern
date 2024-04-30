#include <iostream>
#include <vector>

// Recursive binary search function
int binarySearch(const std::vector<int>& arr, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        } else if (arr[mid] > target) {
            // Search in the left half
            return binarySearch(arr, target, low, mid - 1);
        } else {
            // Search in the right half
            return binarySearch(arr, target, mid + 1, high);
        }
    }

    return -1; // Element not found
}

int main() {
    // Example usage
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;

    std::cout << "Enter the number to search for: ";
    std::cin >> target;

    int result = binarySearch(sortedArray, target, 0, sortedArray.size() - 1);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
