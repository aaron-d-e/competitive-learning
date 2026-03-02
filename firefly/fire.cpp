#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int binarySearch(const int& cur, const vector<int>& height, const int& size) {
    int lower = 0;
    int upper = size;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        if (height.at(mid) >= cur) {
            upper = mid;
        }
        else {
            lower = mid + 1;
        }
    }

    return size - lower;
}

int main() {
    vector<int> top;
    vector<int> bot;

    int n, h;
    cin >> n >> h;

    // read in the input from the file
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (i % 2 == 0) {
            bot.push_back(temp);
        }
        else {
            top.push_back(temp);
        }
    }

    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());

    int best, count = 0;

    int curMin = 2e9;

    for (int i = 1; i <= h; i++) {
        // how many obsts reach to height i
        int t = binarySearch(i, bot, bot.size());
        int b = binarySearch(h - i + 1, top, top.size());

        int obstacleDest = t + b;

        if (curMin > obstacleDest) {
            curMin = obstacleDest;
            count = 1;
        }
        else if (curMin == obstacleDest) {
            count++;
        }
        best = curMin;
    }

    cout << best << " " << count << endl;

    return 0;
}
