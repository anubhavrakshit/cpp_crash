#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

#if 0
vector<long long> solve_one(long long n) {
    map<long long, pair<long long, long long>> map;
    map[1] = {1, 1};

    for (long long i = 1; i <= n; i++) {
        long long left = 2 * i;
        long long right = 2 * i + 1;
        
        long long p = map[i].first;
        long long q = map[i].second;
        map[left] = make_pair(p, p + q);
        map[right] = make_pair(p + q, q);
    }


    return {map[n].first, map[n].second};
}
#endif

vector<unsigned long long> solve_one(unsigned long long n) {
    string in_bin;
    //cout << "dec: " << n << endl;
    while (n) {
        if ((n & 0x1) == 0) {
            in_bin = "0" + in_bin;
        } else {
            in_bin = "1" + in_bin;
        }
        n = n >> 1;
    }
    //cout << "bin: " << in_bin << endl;

    unsigned long long p{1}, q{1};
    for (int i = 1; i < in_bin.length(); i++) {
        if (in_bin[i] == '1') {
            // go right
            p += q;
        } else {
            q += p;
        }
    }

    return {p, q};
}

vector<unsigned long long> solve_two(unsigned long long p,unsigned long long q) {
    string ans;
    while (p != q) {
        if (p > q) {
            p -= q;
            ans = "1" + ans;
        } else {
            q -= p;
            ans = "0" + ans;
        }
    }
    ans = "1" + ans;
    unsigned long long n{0};

    for (int i = 0; i < ans.length(); i++) {
        n *= 2;
        if (ans[i] == '1') {
            n += 1;
        }
    }
    return {n};
}

#if 0
vector<long long> solve_two(long long p, long long q) {
    map<long long, pair<long long, long long>> map;
    map[1] = {1, 1};

    long long i = 1;
    while (true) {
        long long left = 2 * i;
        long long right = 2 * i + 1;
        
        long long p_cur = map[i].first;
        long long q_cur = map[i].second;
        if (p == p_cur and q == q_cur) {
            return {i};
        }
        map[left] = make_pair(p_cur, p_cur + q_cur);
        map[right] = make_pair(p_cur + q_cur, q_cur);
        i++;
    }

    return {};
}
#endif

int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int PID;
    cin >> PID;
    cout << "Case #" << testCase << ": ";
    
    vector<unsigned long long> ans;
    if (PID == 1) {
        unsigned long long n{0};
        cin >> n;
        ans = solve_one(n);
    } else {
        unsigned long long p, q;
        cin >> p >> q;
        ans = solve_two(p, q);
    }
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
