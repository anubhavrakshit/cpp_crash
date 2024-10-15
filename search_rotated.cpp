class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nelems = nums.size();
        int l = 0, r = nelems - 1;
        
        while (l <= r) {
            int m = (l + r)/2;
            
            if (nums[m] == target) {
                return m;
            }
            
            // Non rotated
            if (nums[l] < nums[r]) {
                if (target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[m] >= nums[l]) {
                    if (target >= nums[l] and target < nums[m]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else if (nums[m] <= nums[r]) {
                    if (target > nums[m] and target <= nums[r]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                } 
            }
        }
        
        
        return -1;
    }
};