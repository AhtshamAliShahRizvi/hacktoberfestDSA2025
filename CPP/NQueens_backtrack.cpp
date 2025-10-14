#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int N;
    vector<vector<string>> solutions;

    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check upper column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void solve(int row, vector<string>& board, int n) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }

public:
    void solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);

        cout << "Total Solutions: " << solutions.size() << endl;
        for (const auto& sol : solutions) {
            for (const auto& row : sol) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    NQueens nq;
    nq.solveNQueens(n);

    return 0;
}