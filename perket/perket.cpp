#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

static vector<pair<int, int>> ingredients;
static int difference = INT_MAX;

bool is_solution(vector<bool> const& chosen) {
    int bitterness = 0, sourness = 1;
    bool emptyset = true;
    for (int i = 0; i < chosen.size(); i++) {
        if (chosen.at(i) == true) {
            bitterness += ingredients.at(i).second;
            sourness *= ingredients.at(i).first;
            emptyset = false;
        }
    }
    if (abs(bitterness - sourness) < difference && !emptyset) {
        difference = abs(bitterness - sourness);
    }
    return false;
}

bool combinations(vector<bool>* chosen, size_t position) {
    if (position == chosen->size()) {
        return is_solution(*chosen);
    }

    chosen->at(position) = false;
    if (combinations(chosen, position + 1)) {
        return true;
    }

    chosen->at(position) = true;
    if (combinations(chosen, position + 1)) {
        return true;
    }

    return false;
}

int main() {
    int num_inputs;
    cin >> num_inputs;

    vector<bool> options(num_inputs, false);

    for (int i = 0; i < num_inputs; i++) {
        int temp;
        int temp2;
        cin >> temp >> temp2;
        ingredients.push_back({temp, temp2});
    }
    bool answer = combinations(&options, 0);

    cout << difference << endl;
    return 0;
}
