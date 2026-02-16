#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    size_t n, q;
    cin >> n;
    vector<size_t> cards(n);
    for (auto& c : cards) {
        cin >> c;
    }

    sort(cards.begin(), cards.end());

    cin >> q;
    while (q--) {
        size_t l, r;
        cin >> l >> r;
        auto a = lower_bound(cards.begin(), cards.end(), l);
        auto b = upper_bound(cards.begin(), cards.end(), r);
        cout << distance(a, b) << endl;
    }
    return 0;
}
