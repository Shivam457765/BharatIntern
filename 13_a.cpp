#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack Problem using dynamic programming
int knapsack(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int n = weights.size();

    // Initialize a 2D array to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table bottom-up
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            // If the current item can fit in the knapsack
            if (weights[i - 1] <= w)
            {
                // Choose the maximum value between including and excluding the current item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                // If the current item cannot fit, skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored in the bottom-right cell of the dp table
    return dp[n][capacity];
}

int main()
{
    // Example usage
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    // Input weights and values of each item
    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    // Call the knapsack function
    int maxValue = knapsack(weights, values, capacity);

    // Output the maximum value
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
