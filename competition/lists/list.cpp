#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;

    while (num != 0) {
        vector<pair<int, int> > input(num);
        for (size_t i = 0; i < num; i++) {
            cin >> input.at(i).first;
        }
        for (size_t i = 0; i < num; i++) {
            cin >> input.at(i).second;
        }

        for (const auto& in : input) {
            cout << in.first << " " << in.second << endl;
        }

        cin >> num;
        cout << endl;
    }

    return 0;
}
