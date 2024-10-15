#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

void printBin(int n, string num) {
    if (n == 0) {
        cout << num << endl;
        return;
    }

    printBin(n - 1, num + "0");
    printBin(n - 1, num + "1");
}

void twoDiceSum(int numDice, int targetSum, deque<int> &choice) {
    if (numDice == 0) {
        if (targetSum == 0) {
            for (auto n : choice) {
                cout << n << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if (i <= targetSum) {
            choice.push_back(i);
            twoDiceSum(numDice - 1, targetSum - i, choice);
            choice.pop_back();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> choice;
    twoDiceSum(m, n, choice);
    return 0;
}