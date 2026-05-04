#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    while (std::cin >> n and n > 0) {
        vector<string> names(n);
        for (auto& n : names) {
            cin >> n;
        }
        stable_sort(names.begin(), names.end(),
                    [](const auto& a, const auto& b) {
                        return a.substr(0, 2) < b.substr(0, 2);
                    });

        for (auto n : names) {
            cout << n << endl;
        }
        cout << endl;
    }
}
