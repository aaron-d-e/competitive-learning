#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int binarySearch(const vector<pair<string, int>>& v, int x) {
    size_t low = 0;
    size_t high = v.size();

    while (low < high) {
        int middle = (low + high) / 2;
        if (v[middle].second < x) {
            low = middle + 1;
        }
        else if (x < v[middle].second) {
            high = middle;
        }
        else
            return middle;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> name_scores;
    for (int i = 0; i < n; i++) {
        string name;
        int num;
        cin >> name >> num;
        name_scores.push_back({name, num});
    }

    cin >> n;

    sort(name_scores.begin(), name_scores.end(),
         [](const auto& a, const auto& n) {
             if (a.second < n.second) {
                 return true;
             }
             return false;
         });

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;

        string winner = ":(";
        int cur = INT_MIN;

        int index = binarySearch(name_scores, score);
        if (index != -1) {
            winner = name_scores[index].first;
        }

        /*
        for (auto& name : name_scores) {
            if (name.second > cur && name.second <= score) {
                cur = name.second;
                winner = name.first;
            }
        }
        */
        cout << winner << endl;
    }

    return 0;
}
