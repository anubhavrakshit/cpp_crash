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
        int N, K;
        string input;
        cin >> N >> K;
        cin >> input;
        int ret = get_goodness(input, K);
        cout << "Case #" << tc << ": " << ret << endl;
        tc++;
    }
    return 0;
}