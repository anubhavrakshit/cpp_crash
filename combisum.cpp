void hlpr(int k, int sum, vector<int> &chose, vector<vector<int>> &ans) {
  if (k == 0) {
    if (sum != 0) {
      return;
    }
    ans.push_back(chose);
    return;
  }

  auto start = chose.empty() ? 1 : chose.back() + 1;
  for (int i = start; i < 10; i++) {
    if (i <= sum) {
      chose.push_back(i);
      hlpr(k - 1, sum - i, chose, ans);
      chose.pop_back();
    }
  }
}
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> chose;
    hlpr(k, n, chose, ans);
    return ans;
  }
};