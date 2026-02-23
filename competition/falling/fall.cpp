#include <bits/stdc++.h>
#include <unistd.h>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    vector<int> pieces;

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        pieces.push_back(temp);
    }

    int alice = 0, bob = 0;
    enum { A, B };
    int turn = A;

    while (pieces.size() != 0) {
        int max = -1;
        int index = -1;
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces.at(i) > max) {
                max = pieces.at(i);
                index = i;
            }
        }

        if (turn == A) {
            alice += max;
            pieces.erase(pieces.begin() + index);
            turn = B;
        }
        else {
            bob += max;
            pieces.erase(pieces.begin() + index);
            turn = A;
        }
    }

    cout << alice << " " << bob << endl;

    return 0;
}
