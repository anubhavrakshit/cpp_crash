#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        int num_elems = 0;
        
        sort(arr.begin(), arr.end());
        unordered_map<int, int> count{};
        for (auto x: arr) {
            count[x]++;
        }
        
        for (int i = 0; i < arr.size();) {
            int c_i = 0;
            int num = arr[i];
            
            c_i = count[num];
            if (count[num + 1]) {
                num_elems += c_i;
            }
            
            i += c_i;
        }
        
        return num_elems;
    }
};

int main() {
    Solution s;
    vector<int> test{1,1,3,2,3,5,5,7,7};

    cout << s.countElements(test) << "\n";
    return 0;
}