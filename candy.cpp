#include <iostream>
using namespace std;

int get_goodness(string& input, int K) {
    int ans{0};
    int l = 0 , r = input.length() - 1;

    int gd{0};
    while (l < r) {
        if (input[l] != input[r]) {
            gd++;
        }
        l++;
        r--;
    }

    ans = abs(gd - K);
    return ans;
}

int main() {
    int ntc{0};
    cin >> ntc;
    int tc{1};

    while (ntc--) {
        int N, M;
        cin >> N >> M;
        int total_candies{0};
        while (N--) {
            int nc{0};
            cin >> nc;
            total_candies += nc;
        }
        int ret = (total_candies % M);
        cout << "Case #" << tc << ": " << ret << endl;
        tc++;
    }
    return 0;
}