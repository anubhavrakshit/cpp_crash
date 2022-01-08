#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> depths;
    int d;
    const auto win_sz{3};
    while (cin >> d) {
        depths.push_back(d);
    }

    int prev_win_sum {0};
    for (int i = 0; i < win_sz; i++) {
        prev_win_sum += depths[i];
    }

    int l{0}, r{win_sz};
    int cur_win_sum{prev_win_sum};
    int count{0};
    while (r < depths.size()) {
        cur_win_sum += depths[r++] - depths[l++];
        if (cur_win_sum > prev_win_sum) {
            count++;
        }
        prev_win_sum = cur_win_sum;
    }
    cout << "Num inc = " << count << endl;
    return 0;
}