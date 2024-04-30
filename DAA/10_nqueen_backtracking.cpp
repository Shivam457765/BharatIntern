#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, const vector<int>& placement) {
    // Check if no queens are in the same column or diagonals
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        if (placement[prevRow] == col ||  // Check same column
            abs(placement[prevRow] - col) == abs(prevRow - row)) {  // Check diagonals
            return false;
        }
    }
    return true;
}

void printBoard(const vector<int>& placement) {
    int N = placement.size();
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (placement[row] == col) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int row, int N, vector<int>& placement) {
    if (row == N) {
        // All queens are placed successfully
        printBoard(placement);
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col, placement)) {
            // Place queen and move to the next row
            placement[row] = col;
            solveNQueens(row + 1, N, placement);
            // Backtrack and try placing the queen in a different column
            placement[row] = -1;
        }
    }
}

void nQueens(int N) {
    vector<int> placement(N, -1);  // Initialize with no queens placed
    solveNQueens(0, N, placement);
}

int main() {
    int N;
    cout << "Enter the\nsize of the\nchessboard (N): ";
    cin >> N;

    nQueens(N);

    return 0;
}
