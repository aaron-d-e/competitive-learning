#include <bits/stdc++.h>
using namespace std;

size_t inversions(const vector<int>& nums) {
    size_t size = nums.size();
    size_t count = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums.at(i) > nums.at(j)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    size_t num_inputs;
    cin >> num_inputs;

    for (size_t i = 0; i < num_inputs; i++) {
        vector<int> nums;
        cout << i + 1 << " ";
        int trash;
        cin >> trash;
        for (size_t j = 0; j < 20; j++) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        cout << inversions(nums) << endl;
    }
    return 0;
}
