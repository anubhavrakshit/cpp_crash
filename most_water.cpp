class Solution {
public:
    int maxArea(vector<int>& height) {

        int max_store{0};
        int nb = height.size();
        int l{0}, r{nb - 1};
        
        while (l < r) {
            int horz_d = r - l;
            int low_height = min(height[l], height[r]);
            max_store = max(max_store, (low_height * horz_d));
            
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_store;
    }
};