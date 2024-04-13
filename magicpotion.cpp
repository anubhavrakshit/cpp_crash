int bsearch(int spell, vector<int>& potions, long long success) {
  int low = 0, high = potions.size() - 1;
  bool found{false};
  while (low <= high) {
    auto mid = (low + high) / 2;
    long long prod = (long long)spell * (long long)potions[mid];
    if (prod >= success) {
      found = true;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (found) {
    return potions.size() - high - 1;
  }
  return 0;
}
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       sort(potions.begin(), potions.end());
       vector<int> ans;
       for (auto spell : spells) {
        auto count = bsearch(spell, potions, success);
        ans.push_back(count);
       }
       return ans;
    }
};