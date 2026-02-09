#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

set<int> values;
set<pair<int, int>> visited;

void generate(int digit, int number) {
    if (number > 200) return;

    if (visited.count({digit, number}))
        return;  // stop recursion if already visited
    visited.insert({digit, number});

    if (digit == 1) {
        generate(2, number);
        generate(4, number);
        number = number * 10 + digit;
        if (number <= 200) {
            values.insert(number);
        }
        generate(1, number);
        generate(2, number);
        generate(4, number);
    }
    if (digit == 2) {
        generate(3, number);
        generate(5, number);
        number = number * 10 + digit;
        if (number <= 200) {
            values.insert(number);
        }
        generate(2, number);
        generate(3, number);
        generate(5, number);
    }
    if (digit == 3) {
        generate(6, number);
        number = number * 10 + digit;
        if (number <= 200) {
            values.insert(number);
        }
        generate(3, number);
        generate(6, number);
    }
    if (digit == 9) {
        number = number * 10 + digit;
        if (number <= 200) {
            values.insert(number);
        }
        generate(9, number);
    }
    if (digit == 0) {
        number = number * 10 + digit;
        if (number <= 200) {
            values.insert(number);
        }
        if (number != 0) {
            generate(0, number);
        }
    }
    if (digit == 4) {
        generate(5, number);
        generate(7, number);
        number = number * 10 + digit;

        if (number <= 200) {
            values.insert(number);
        }
        generate(4, number);
        generate(5, number);
        generate(7, number);
    }
    if (digit == 5) {
        generate(6, number);
        generate(8, number);
        number = number * 10 + digit;

        if (number <= 200) {
            values.insert(number);
        }
        generate(5, number);
        generate(6, number);
        generate(8, number);
    }
    if (digit == 6) {
        generate(9, number);
        number = number * 10 + digit;
        if (number <= 200) {
            values.insert(number);
        }
        generate(6, number);
        generate(9, number);
    }
    if (digit == 7) {
        generate(8, number);
        number = number * 10 + digit;

        if (number <= 200) {
            values.insert(number);
        }
        generate(7, number);
        generate(8, number);
    }
    if (digit == 8) {
        generate(0, number);
        generate(9, number);
        number = number * 10 + digit;

        if (number <= 200) {
            values.insert(number);
        }
        generate(8, number);
        generate(0, number);
        generate(9, number);
    }
}

int main() {
    int num;
    cin >> num;

    generate(1, 0);  // generate all possible numbers

    vector<int> sorted_vals;
    for (const auto& num : values) {
        sorted_vals.push_back(num);
    }
    sort(sorted_vals.begin(), sorted_vals.end());

    for (int i = 0; i < num; i++) {
        int k;
        cin >> k;  // read input

        if (find(sorted_vals.begin(), sorted_vals.end(), k) !=
            sorted_vals.end()) {
            cout << k << endl;
        }
        else {
            for (int i = 0; i < sorted_vals.size() - 1; i++) {
                if (sorted_vals.at(i) < k && k < sorted_vals.at(i + 1)) {
                    if (k - sorted_vals.at(i) < sorted_vals.at(i + 1) - k) {
                        cout << sorted_vals.at(i) << endl;
                    }
                    else {
                        cout << sorted_vals.at(i + 1) << endl;
                        ;
                    }
                }
            }
        }
    }
    return 0;
}
