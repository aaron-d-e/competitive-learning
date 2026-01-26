#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    // need to track position of each star as well as their region, row, and
    // column

    int board[10][10];
    vector<pair<int, int> > stars;  // vector of star positions
    map<int, int> regions;
    bool valid = true;

    for (int i = 0; i < 10; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 10; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    for (int i = 0; i < 10; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 10; j++) {
            if (line[j] == '*') {
                stars.push_back({i, j});
                regions[board[i][j]] += 1;  // map for region star count
            }
        }
    }

    if (stars.size() != 20 || regions.size() != 10) {
        valid = false;
        cout << "invalid" << endl;
        return 0;
    }

    // check if each row has two stars - rows are already sorted at this point

    for (int i = 0; i < stars.size() - 1; i = i + 2) {
        if (stars.at(i).first != stars.at(i + 1).first) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "invalid" << endl;
        return 0;
    }

    sort(stars.begin(), stars.end(),
         [](const auto& a, const auto& b) { return a.second < b.second; });

    // now check the same thing for columns - then we need to check
    // region(iterate through starts and reference board)

    for (int i = 0; i < stars.size() - 1; i = i + 2) {
        if (stars.at(i).second != stars.at(i + 1).second) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "invalid" << endl;
        return 0;
    }

    // check for region

    for (const auto& r : regions) {
        if (r.second != 2) {  // two stars per region
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "invalid" << endl;
        return 0;
    }

    // check for adjacency

    vector<pair<int, int> > directions = {{1, 0}, {0, 1},  {0, -1}, {-1, 0},
                                          {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    for (const auto& s : stars) {
        for (const auto& d : directions) {
            for (const auto& in : stars) {
                if (s != in) {
                    if ((s.first + d.first == in.first) &&
                        (s.second + d.second == in.second)) {
                        valid = false;
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "valid" << endl;

    return 0;
}
