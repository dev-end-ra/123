#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>>& board, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    // Check upper column
    for(int i = 0; i < row; i++)
        if(board[i][col] == 1) return false;

    // Check upper-left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 1) return false;

    // Check upper-right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if(board[i][j] == 1) return false;

    return true;
}

void solveNQueen(int row, int n, vector<vector<int>>& board) {
    if(row == n) {
        printBoard(board, n);  // print one solution
        return;
    }

    for(int col = 0; col < n; col++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solveNQueen(row + 1, n, board);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solveNQueen(0, n, board);
    return 0;
}
