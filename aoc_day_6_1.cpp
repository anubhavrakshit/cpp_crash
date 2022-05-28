#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> fish_table;

    for (int i; ss >> i; ) {
        fish_table.push_back(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    int day = 0;
    while (day < 256) {
        int births{0};
        day++;
        for (auto &age : fish_table) {
            age--;
            if (age == -1) {
                age = 6;
                births++;
            }
        }

        while (births) {
            fish_table.push_back(8);
            births--;
        }
        #if 0
        for (auto a : fish_table) {
            cout << a << ",";
        }
        cout << endl;
        #endif
    }
    //cout << "Ans = " << fish_table.size() << endl;
    return 0;
}