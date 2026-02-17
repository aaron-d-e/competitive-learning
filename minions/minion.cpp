#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
    size_t inputs;
    cin >> inputs;
    vector<pair<int, int> > temps;

    for (size_t i = 0; i < inputs; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        temps.push_back(temp);
    }

    sort(temps.begin(), temps.end(),
         [](auto& a, auto& b) { return a.second < b.second; });

    if (temps.empty()) {
        cout << 0 << endl;
        return 0;
    }

    size_t rooms = 0;
    int currentTemp = -1;
    for (const auto& temp : temps) {
        if (temp.first > currentTemp) {
            rooms++;
            currentTemp = temp.second;
        }
    }
    cout << rooms << endl;
    return 0;
}
