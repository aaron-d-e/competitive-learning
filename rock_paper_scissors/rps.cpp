#include <iostream>
#include <string>
using namespace std;

int main() {
    string temp1, temp2;
    while (cin >> temp1 && cin >> temp2) {
        pair<int, int> scores = {0, 0};  // p1, p2
        if (temp1 == "E" && temp2 == "E") break;

        // probably a better way than nested but small data set

        for (int i = 0; i < temp1.length(); i++) {
            if (temp1[i] == temp2[i]) continue;  // next iteration if tie

            if (temp1[i] == 'R') {
                if (temp2[i] == 'P')
                    scores.second += 1;
                else
                    scores.first += 1;
            }
            else if (temp1[i] == 'P') {
                if (temp2[i] == 'S')
                    scores.second += 1;
                else
                    scores.first += 1;
            }
            else {  // p1 is S
                if (temp2[i] == 'R')
                    scores.second += 1;
                else
                    scores.first += 1;
            }
        }

        cout << "P1: " << scores.first << endl;
        cout << "P2: " << scores.second << endl;
    }

    return 0;
}
