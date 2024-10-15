#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void hlpr(string &digits, size_t pos, string chose,
          unordered_map<char, vector<char>> &map, vector<string> &ans) {
  if (pos == digits.length()) {
    ans.push_back(chose);
    return;
  }

  for (auto letter : map[digits[pos]]) {
    hlpr(digits, pos + 1, chose + letter, map, ans);
  }
}
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    unordered_map<char, vector<char>> map = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };

    cout << digits << endl;
    vector<string> ans;
    string chose;
    hlpr(digits, 0, chose, map, ans);
    return ans;
  }
};

int main() {
    Solution s;
    auto combo = s.letterCombinations("297");
    for (auto word : combo) {
        cout << word << endl;
    }
    return 0;
}