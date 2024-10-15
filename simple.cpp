#include <iostream>
#include <vector>

using namespace std;

int solve(int A) {
    vector<int> circle(A);
    for (int i = 0; i < A; i++) {
        circle[i] = i + 1;
    }
    int pos_del = -1;
    while (!circle.empty()) {
        if (circle.size() == 1) {
            break;
        }
        vector<int> selected;
        for (int i = 0; i < circle.size(); i++) {
            if (i % 2 != 0) {
                cout << "Select " << circle[i] << endl;
                selected.push_back(circle[i]);
            }
        }
        circle.resize(0);
        circle = selected;
    }
    cout << "Ans " << circle[0];
    return circle[0];   
}

int main() {
    solve(10);
    return 0;
}