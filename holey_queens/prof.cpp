#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<bool>> Board;

unsigned int diagonal1(Board const& board, size_t row, size_t column) {
    return row + column;
}

unsigned int diagonal2(Board const& board, size_t row, size_t column) {
    return board.size() - row + column - 1;
}

unsigned int solve(Board const& board, vector<bool>* column_used,
                   vector<bool>* diagonal1_used, vector<bool>* diagonal2_used,
                   size_t row) {
    if (row == board.size()) {
        return 1;
    }

    unsigned int answer = 0;
    for (size_t column = 0; column < board[row].size(); ++column) {
        if (not(board[row][column] or column_used->at(column) or
                diagonal1_used->at(diagonal1(board, row, column)) or
                diagonal2_used->at(diagonal2(board, row, column)))) {
            column_used->at(column) = true;
            diagonal1_used->at(diagonal1(board, row, column)) = true;
            diagonal2_used->at(diagonal2(board, row, column)) = true;

            answer += solve(board, column_used, diagonal1_used, diagonal2_used,
                            row + 1);
        }
    }
    return answer;
}

int main() {
    size_t n, m;
    while ((std::cin >> n >> m) and (n != 0)) {
        Board board(n, Row(n, EMPTY));
        for (size_t i = 0; i < m; ++i) {
            size_t r, c;
            std::cin >> r >> c;
            board[r][c] = true;
        }
    }
}
