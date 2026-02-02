#include <bits/stdc++.h>
#include <climits>
#include <numeric>
#include <string>
using namespace std;

static int answer = INT_MAX;
static int input;

bool is_solution(vector<int> const& order) {
    int temp = accumulate(order.begin(), order.end(), 0,
                          [](auto a, auto b) { return (a * 10 + b); });

    if (temp > input && temp < answer) {
        answer = temp;
    }
    return false;
}

bool permutations(vector<int>* order, size_t position) {
    if (position == order->size()) {
        return is_solution(*order);
    }

    for (size_t i = position; i < order->size(); ++i) {
        swap(order->at(position), order->at(i));
        if (permutations(order, position + 1)) {
            return true;
        }
        swap(order->at(position), order->at(i));
    }

    return false;
}

int main() {
    vector<int> sequence;

    cin >> input;
    string s = to_string(input);

    for (const auto& c : s) {
        sequence.push_back(c - '0');
    }

    bool ans = permutations(&sequence, 0);

    if (answer == INT_MAX) {
        cout << 0 << endl;
    }
    else {
        cout << answer << endl;
    }

    return 0;
}
