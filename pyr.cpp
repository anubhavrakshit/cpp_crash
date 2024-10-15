#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A = 20;
    vector<int> prev = {1};
    for (int i = 1 ; i <= A; i++) {
        vector<int> cur(i + 1, -1);
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                cur[j] = prev[0];
            } else if (j == i) {
                cur[j] = prev[i - 1];
            } else {
                cur[j] = prev[j] + prev[j - 1];
            }
        }
        for (auto n : cur) {
            cout << n << " ";
        }
        cout << endl;
        prev = cur;
    }
    return 0;
}