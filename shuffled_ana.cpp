#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool shuffle(string &in, unordered_map<char, int> &fc, int pos, string &ans) {
   if (ans.length() == in.length()) {
       return true;
   } 

   for (auto &f : fc) {
    if (f.first == in[pos] || f.second == 0) {
        continue;
    
    }

    // choose
    f.second--; 
    //cout << "chose " << f.first << " count " << f.second << endl;
    ans += f.first;
    bool ret = shuffle(in, fc, pos + 1, ans);
    if (ret == true) {
        return true;
    }
    // unchoose
    ans.pop_back();
    f.second++;              
   }

   return false;
}


int main() {
    int ntc{0};
    cin >> ntc;
    int c{1};

    while (ntc--) {
        string ana;
        cin >> ana;
        bool ret{false};
        string ans;
        unordered_map<char , int> fc;
        for (auto c : ana) {
            fc[c]++;
        }
        ret = shuffle(ana, fc, 0, ans);
        if (ret) {
            cout << "Case #" << c << ": " << ans << endl;
        } else {
            cout << "Case #" << c << ": " << "IMPOSSIBLE" << endl;
        }
        c++;
    }
    return 0;
}