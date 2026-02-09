#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

vector<pair<size_t, size_t>> holes;

bool column_available(vector<vector<bool>> const& board, size_t max_row,
                      size_t column) {
    for (size_t row = 0; row < max_row; ++row) {
        if (board[row][column]) {
            return false;
        }
    }
    return true;
}
bool diagonals_available(vector<vector<bool>> const& board, size_t max_row,
                         size_t column) {
    for (size_t i = 1; i <= max_row; ++i) {
        size_t row = max_row - i;
        if (i <= column and board[row][column - i]) {
            return false;
        }
        if (column + i < board[row].size() and board[row][column + i]) {
            return false;
        }
    }
    return true;
}

bool nqueens(vector<vector<bool>>& board, size_t row, int& count) {
    if (row == board.size()) {
        count++;
        return false;
    }
    for (size_t column = 0; column < board[row].size(); ++column) {
        if (column_available(board, row, column) and
            diagonals_available(board, row, column) and
            find(holes.begin(), holes.end(), make_pair(row, column)) ==
                holes.end()) {  // and not a hole
            board[row][column] = true;
            if (nqueens(board, row + 1, count)) {
                return false;
            }
            board[row][column] = false;
        }
    }
    return false;
}

int main() {
    // n m where n is half the board and m is the number of holes
    pair<int, int> params;
    vector<vector<bool>> board;
    cin >> params.first >> params.second;
    while (!(params.first == 0 && params.second == 0)) {
        for (int i = 0; i < params.second; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            holes.push_back({temp1, temp2});
        }

        for (int i = 0; i < params.first; i++) {
            vector<bool> temp(params.first, false);
            board.push_back(temp);
        }

        int count = 0;
        nqueens(board, 0, count);
        cout << count << endl;

        cin >> params.first >> params.second;
        holes.clear();
        board.clear();
    }

    return 0;
}
