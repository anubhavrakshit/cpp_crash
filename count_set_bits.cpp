class Solution {
public:
    int num_ones(unsigned x) {
        unsigned first_set{0};
        int count{0};
        while (x) {
            first_set = x & (-x);
            if (first_set) {
                count++;
            } else {
                break;
            }
            x &= ~first_set;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            ans[i] = num_ones(i);
        }
        
        return ans;
    }
};