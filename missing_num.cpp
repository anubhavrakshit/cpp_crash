class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned ans{0};
        auto n{nums.size()};
        // 0^3^1^0^2^1 
        // 
        for (int i = 0; i < n; i++) {
            ans ^= (nums[i] ^ (i + 1));
        }    
        return ans;
    }
};