#include <bits/stdc++.h>
#include <string>
#include <tuple>
using namespace std;

int valid_dates = 0;
int* soonest_date = new int[3]{99, 99, 9999};
set<tuple<int, int, int>> seen_dates;

map<string, int> month_days = {{"01", 31}, {"02", 28}, {"03", 31}, {"04", 30},
                               {"05", 31}, {"06", 30}, {"07", 31}, {"08", 31},
                               {"09", 30}, {"10", 31}, {"11", 30}, {"12", 31}};

string getDay(vector<int> const& date) {
    return to_string(date[0]) + to_string(date[1]);
}
string getMonth(vector<int> const& date) {
    return to_string(date.at(2)) + to_string(date[3]);
}
string getYear(vector<int> const& date) {
    return to_string(date.at(4)) + to_string(date.at(5)) +
           to_string(date.at(6)) + to_string(date.at(7));
}

bool isValidDate(string day, string month, string year) {
    if ((stoi(year) % 400 == 0) ||
        (stoi(year) % 4 == 0 && stoi(year) % 100 != 0)) {
        // is a leap year
        month_days["02"] = 29;
        // cout << "This year is a leap year!" << endl;
    }
    else {
        // not a leap year
        month_days["02"] = 28;
    }

    if (stoi(year) < 2000) {
        // cout << "Not a valid year!" << endl;
        return false;
    }

    if (stoi(month) < 1 || stoi(month) > 12) {
        // cout << "Not a valid month" << endl;
        return false;
    }

    if (stoi(day) < 1 || stoi(day) > month_days.at(month)) {
        // cout << "Not a valid day!" << endl;
        return false;
    }

    // cout << "Valid Date!" << endl;
    //
    // insert on a set returns pair<iterator, bool>
    auto date = make_tuple(stoi(day), stoi(month), stoi(year));
    if (seen_dates.insert(date).second) {
        valid_dates++;
    }

    auto comp_soonest = make_tuple(stoi(year), stoi(month), stoi(day));
    auto cur_soonest =
        make_tuple(soonest_date[2], soonest_date[1], soonest_date[0]);

    if (comp_soonest < cur_soonest) {  // compare tuples
        soonest_date[2] = stoi(year);
        soonest_date[1] = stoi(month);
        soonest_date[0] = stoi(day);
    }

    return true;
}

bool is_solution(vector<int> const& order) {
    // for (int num : order) {
    //     cout << num;
    // }
    //  cout << endl << " " << "Day: " << getDay(order) << endl;
    //  cout << " " << "Month: " << getMonth(order) << endl;
    //  cout << " " << "Year: " << getYear(order) << endl;

    isValidDate(getDay(order), getMonth(order),
                getYear(order));  // updates valid_dates, returns bool

    return false;
}

bool permutations(vector<int>* order, size_t position) {
    if (position == order->size()) {
        return is_solution(*order);
    }

    for (size_t i = position; i < order->size(); i++) {
        swap(order->at(position), order->at(i));
        if (permutations(order, position + 1)) {
            return true;
        }
        swap(order->at(position), order->at(i));
    }

    return false;
}

int main() {
    vector<vector<int>> dates;

    int num_inputs;
    cin >> num_inputs;
    for (int i = 0; i < num_inputs; i++) {
        vector<int>* temp = new vector<int>;  // create new vector

        string day, month, year;
        cin >> day >> month >> year;

        string date = day + month + year;

        for (const auto& ch : date) {
            temp->push_back(ch - '0');  // convert string into a vector of ints
        }

        dates.push_back(*temp);
        delete temp;
    }

    for (auto v : dates) {
        bool ans = permutations(&v, 0);

        if (valid_dates == 0) {
            cout << 0 << endl;
        }
        else {
            cout << valid_dates << " " << setfill('0') << setw(2)
                 << to_string(soonest_date[0]) << " " << setw(2)
                 << to_string(soonest_date[1]) << " "
                 << to_string(soonest_date[2]) << endl;
        }

        valid_dates = 0;
        delete[] soonest_date;
        soonest_date = new int[3]{99, 99, 9999};
        seen_dates.clear();
    }

    return 0;
}
