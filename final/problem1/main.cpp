#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        char seq[32];

        for (int i = 0; i < 32; i++) {
            seq[i] = '?';
        }

        for (int i = 0; i < n; i++) {
            string command;
            cin >> command;

            if (command == "CLEAR") {
                int bit;
                cin >> bit;
                seq[bit] = '0';
            }
            else if (command == "SET") {
                int bit;
                cin >> bit;

                seq[bit] = '1';
            }
            else if (command == "AND") {
                int i, j;
                cin >> i >> j;
                // seq[i] = seq[i] & seq[j];
                if (seq[i] == seq[j] && seq[i] == '1') {
                    seq[i] = '1';
                }
                else if (seq[j] == '0' || seq[i] == '0') {
                    seq[i] = '0';
                }
                else {
                    seq[i] = '?';
                }
            }
            else if (command == "OR") {
                int i, j;
                cin >> i >> j;
                //                seq[i] = seq[i] | seq[j];
                if (seq[i] == '1' || seq[j] == '1') {
                    seq[i] = '1';
                }
                else if (seq[i] == '?' || seq[j] == '?') {
                    seq[i] = '?';
                }
                else {
                    seq[i] = '0';
                }
            }
        }
        for (int i = 31; i >= 0; i--) {
            cout << seq[i];
        }
        cout << endl;
    }

    return 0;
}
