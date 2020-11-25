#include <iostream>
#include <vector>
using namespace std;

void diceSumHelper(int n, vector<int>& choosen, int sum) {
    if (n == 0) {
        if (sum == 0) {
            for (auto i : choosen) {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if (i > sum) {
            continue;
        }

        choosen.push_back(i);
        diceSumHelper(n - 1, choosen, sum - i);
        choosen.pop_back();
    }
}

void diceSum(int n, int sum) {
    vector<int> choosen;
    return diceSumHelper(n, choosen, sum);
}
int main() {
    int num_dice{10}, target_sum{45};
    diceSum(num_dice, target_sum);
    return 0;
}