#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

long long min_trees(vector<long long> &line, long long k) {
    long long n = line.size();
    vector<long long> psum(n + 1, 0);
    bool impos{true};
    for (long long i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + line[i - 1];
        if (psum[i] >= k) {
            impos = false;
        }
    }
    if (impos) {
        return -1;
    }

    // Find seg1 and seg2 such that sum(seg1) + sum(seg2) == k && len(seg1) + len(seg2) is min

    long long min_len = n + 1;
    bool found{false};
    for (long long i = 1; i < n; i++) {
        for (long long j = 1; j <= n; j++) {
             long long seg1_len = j - i + 1;
             long long seg1_sum = psum[j] - psum[i - 1];
             long long seg2_len{0};
             long long seg2_sum{0};
             if (seg1_sum > k) {
                 break;
             }
             // get seg2 
             for (long long m = j + 1; m <= n; m++) {
                 for (long long l = m; l <= n; l++) {
                    seg2_sum = psum[l] - psum[m - 1];
                    seg2_len = l - m + 1;
                    if ((seg1_sum + seg2_sum) == k) {
                        min_len = min(min_len, seg1_len + seg2_len);
                        found = true;
                    }
                 }
             }
             if (seg1_sum == k) {
                 found = true;
                 min_len = min(min_len, seg1_len);
             }
        }
    }

    if (!found) {
        return -1;
    }
    return min_len;
}
int main() {
    long long ntc{0};
    cin >> ntc;
    long long tc{1};

    while (ntc--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> line(n);
        for (long long i = 0; i < n; i++) {
            long long nb{0};
            cin >> nb;
            line[i] = nb;
        }

        long long ret = min_trees(line, k);
        cout << "Case #" << tc << ": " << ret << endl;
        tc++;
    }
    return 0;
}