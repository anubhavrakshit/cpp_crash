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

    // Tables to hold number of fishes of given age
    vector<long> cur_gen(9, 0), next_gen(9, 0);
    // Ages range from 0 - 8
    // cur_gen captures the number of fishes of given age i in cur_gen[i]
    // Special transition from 0 -> 6. Indicates New Birth and Reset Age to 6
    // How to scan a generation table
    // Start from age 1 to age 8
    // Copy each fish for a given age from cur_gen to lower age in next_gen table
    // Copy age 0 to age 6 and age 8 as we should give birth to new fish and reset age to 6 simultaneously 
    // Increment count in Next Gen Table

    // Populate cur_gen from given input
    for (auto age : fish_table) {
        cur_gen[age]++;
    }

    // Life begins at Day 0
    int day{0};
    while (day < 256) {
        // Create next_gen table for next day
        day++;
        for (int i = 1; i < 9; i++) {
            next_gen[i - 1] += cur_gen[i];
        }

        // 0 age will transition to 6 
        // 0 age will create new fish of age 8
        if (cur_gen[0]) {
            next_gen[8] += cur_gen[0];
            next_gen[6] += cur_gen[0];                        
        }

        // Copy the next_gen to cur_gen and clear next_gen
        cur_gen = next_gen;
        for (auto &f : next_gen) {
            f = 0;
        
        // Debug traces 
        cout << "Day " << day << " ";
        for (auto age : cur_gen) {
            cout << age << ",";
        }
        cout << endl;
    }

    long total{0};
    for (auto num : cur_gen) {
        total += num;
    }

    cout << "Ans = " << total << endl;
    return 0;
}