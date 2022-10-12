#include <iostream>
#include <string>

using namespace std;

int num_min_ops(string &input, int n_val, int k_val) {
    int score{0};
    int l{0}, r{n_val - 1};
    while (l < r) {
        if (input[l] != input[r]) {
            score++;
        }
        l++;
        r--;
    }

    return abs(score - k_val);
}


int main()
{
    int num_tc, tc{1};
    int k_val, n_val;

    cin >> num_tc;
    while (num_tc--) {
        string input;
        cin >> n_val >> k_val;
        cin >> input;
        int ans = num_min_ops(input, n_val, k_val);
        cout << "Case #" << tc << ": " << ans << endl;
        tc++;      
    }

    return 0;
}