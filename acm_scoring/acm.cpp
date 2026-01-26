#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // need to keep track of the problems already solved and how many attempts
    // for each
    map<char, bool> solutions;  // could push into one structure using a pair,
                                // but thought it would be unneeded complexity
    map<char, int> minutes;
    int minute;
    char problem;
    string solved;

    string input;

    while (getline(cin, input)) {
        stringstream ss(input);

        ss >> minute >> problem >> solved;

        if (minute == -1) {
            break;
        }

        if (solved == "right") {  // if solved add the minutes to the key -
                                  // will add on top of penalties
            solutions[problem] = true;
            minutes[problem] += minute;
        }
        else {  // if not solved, then add 20 minute penalty
            minutes[problem] += 20;
        }
    }

    pair<int, int> score = {solutions.size(), 0};  // solutions, minutes

    for (const auto& sol : solutions) {
        score.second += minutes[sol.first];
    }

    cout << score.first << " " << score.second << endl;

    return 0;
}
