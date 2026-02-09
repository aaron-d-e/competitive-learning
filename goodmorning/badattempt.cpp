#include <bits/stdc++.h>
#include <climits>
#include <string>
using namespace std;

// recursive depth first search - make the graph iteratively each recursive call
// need to account

int nodes[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, 0, -1};

bool checkBounds(pair<int, int> pos) {
    return pos.first < 4 && pos.second < 3 && pos.first > -1 && pos.second > -1;
}

pair<int, int> moveRight(pair<int, int> pos) {
    pair<int, int> newpos = {pos.first, pos.second + 1};
    if ((newpos.first == 3 && (newpos.second == 0 || newpos.second == 2)) ||
        !checkBounds(newpos)) {
        return {-1, -1};
    }
    return newpos;
}
pair<int, int> moveDown(pair<int, int> pos) {
    pair<int, int> newpos = {pos.first + 1, pos.second};
    if ((newpos.first == 3 && (newpos.second == 0 || newpos.second == 2)) ||
        !checkBounds(newpos)) {
        return {-1, -1};
    }
    return newpos;
}

// bound checks

bool compare(pair<int, int> c1, pair<int, int> c2) {
    return c1.first == c2.first && c1.second == c2.second;
}

void DFShelper(pair<int, int> source, string& cur_number, const int& optimal,
               int& answer, int& diff) {
    if (compare(source, {-1, -1})) {
        return;
    }
    cur_number.append(to_string(nodes[source.first][source.second]));

    int value = stoi(cur_number);
    if (abs(value - optimal) < diff) {
        diff = abs(value - optimal);
        answer = value;
    }

    DFShelper(source, cur_number, optimal, answer, diff);
    DFShelper(moveDown(source), cur_number, optimal, answer, diff);
    DFShelper(moveRight(source), cur_number, optimal, answer, diff);
    cur_number.erase(cur_number.end() - 1);

    return;
}

void DFS(int optimal_ans) {
    int answer = -1;
    string cur_number = "";
    int diff = INT_MAX;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (nodes[row][col] != -1) {
                DFShelper({row, col}, cur_number, optimal_ans, answer, diff);
                cur_number = "";
            }
        }
    }
    cout << answer << endl;
}

int main() {
    int nums;
    cin >> nums;
    vector<int> input;

    for (int i = 0; i < nums; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    for (const auto& num : input) {
        DFS(num);
    }

    return 0;
}
