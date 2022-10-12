#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string shortest(string& palin) {
    string ans;
    int orig_len = palin.length();
    for (int i = 0; i < orig_len; i++) {
        palin.push_back(palin[i]);
        //cout << "Try: " << concat << endl;
        
        int l = 0, r = palin.length() - 1;

        bool is_palin {true};
        while (l < r) {
            if (palin[l] != palin[r]) {
                is_palin = false;
                break;
            }
            l++;
            r--;
        }
       
        if (is_palin) {
            ans = palin.substr(0, i + 1);
            return ans;
        }
    }
    return ans;
}

int main() {
    int ntc{0};
    cin >> ntc;
    int tc{1};

    while (ntc--) {
        int n;
        string palin;
        cin >> n >> palin;
        string ret = shortest(palin);
        cout << "Case #" << tc << ": " << ret << endl;
        tc++;
    }
    return 0;
}