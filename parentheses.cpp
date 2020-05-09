#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // l is num of left paren and r is num of right paren
    // Start with (  left paren and keep on generating string till l has not reached n
    void bt(vector<string>& res,string s, int l, int r, int n) {
        if (l == n && r == n) {
            res.push_back(s);
            return;
        }
        
        if (l < n) {
            bt(res, s + "(", l + 1, r, n);
        }
        if (r < l) {
            bt(res, s + ")", l, r + 1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        // Permutation of parentheses
        vector<string> res;
        bt(res, "", 0, 0, n);
        return res;
    }
};

int main() {
    Solution s;
    auto result = s.generateParenthesis(4);

    for (auto r: result) {
        cout << r << "\n";
    }

    return 0;   
}