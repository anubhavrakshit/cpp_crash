class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        // TC: O(n2)
        // SC: O(n)
        sort(nums.begin(), nums.end());
        set<vector<int>> dup;
        for (int i = 0; i < n; i++) {
            int digit1 = nums[i];
            // Two pointers
            int l{i + 1}, r{n -1};
            
            while (l < r) {
                int mid = (l + r) / 2;
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum == 0) {
                    vector<int> pos_ans = {nums[i], nums[l], nums[r]};
                    if (!dup.count(pos_ans)) {
                        ans.push_back(pos_ans);
                        dup.insert(pos_ans);
                    }
                    l++;r--;
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        
        return ans;
    }
};