#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // Use two stacks to hold previous '(' and '*'
        // alongwith their positions.
        // Position is important when we need to remaining '(' with '*'
        stack<pair<char,int>> oparen, stars;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                oparen.push(make_pair(s[i], i));
            }  else if (s[i] == '*') {
               stars.push(make_pair(s[i], i));
            } else if (s[i] == ')') {
                if (!oparen.empty()) {
                    oparen.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            }
        }
        
        // match up remaining '('
        while (!oparen.empty()) {
            if (!stars.empty() && stars.top().second  > oparen.top().second) {
                oparen.pop();
                stars.pop();
            } else {
                return false;
            }
        }
       
        return true;
    }
};

int main() {
    Solution s;
    string test{"(*))"};
    if (s.checkValidString(test)) {
        cout << "Valid\n";
    } else {
        cout << "In Valid\n";
    }
    return 0;    
}