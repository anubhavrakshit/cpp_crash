#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        // Find the pivot
        // 1. No rotation then left most
        // 2. mid > right then look to right
        // 3. mid < left then look left
        
        int nelems = nums.size();
        int l{0}, r{nelems - 1};
        int ans{nums[0]};
        while (l <= r) {
            int mid = (l + r) / 2;
            int midval = nums[mid];
            
            // Pivot
            if (mid - 1 >= 0) {
                if (midval < nums[mid - 1]) {
                    ans = midval;
                    break;
                }
            }
            
            if (midval  > nums[l] and midval < nums[r]) {
                ans = nums[l];
                break;
            } else if (midval > nums[r]) {
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }
        
        return ans;
    }
};