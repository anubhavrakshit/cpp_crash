#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax, localMax;
        globalMax = localMax = nums[0];

       // kadanes algo:
       // either the number should increase the sum of subarray or we reset the sum to the number 
        for (int i = 1; i < nums.size(); i++) {
            localMax = max(localMax + nums[i], nums[i]);
            if (localMax > globalMax) {
                globalMax = localMax;
            }
        }
        
        return globalMax;
    }
};


int main() {
    vector <int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << "maxSubArray = " << s.maxSubArray(nums) << "\n";
    return 0;
}