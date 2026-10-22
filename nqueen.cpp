#include <iostream>
#include <vector>
using namespace std;

int solutionCount = 0;
int backtrackCount = 0;

void printBoard(vector<vector<int>>& board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int n)
{
    if (row == n)
    {
        solutionCount++;

        cout << "============================\n";
        cout << "Solution " << solutionCount << ":\n";
        printBoard(board, n);

        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;

            cout << "Placed queen at (" << row << ", " << col << ")\n";
            printBoard(board, n);

            solveNQueens(board, row + 1, n);

            cout << "Backtracking: removing queen from ("
                 << row << ", " << col << ")\n";

            board[row][col] = 0;

            backtrackCount++;

            printBoard(board, n);
        }
    }
}

int main()
{
    int n;

    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solveNQueens(board, 0, n);

    cout << "============================\n";
    cout << "Total solutions: " << solutionCount << endl;
    cout << "Total backtracking operations: "
         << backtrackCount << endl;

    return 0;
}