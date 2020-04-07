#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> out;
        map<string, vector<string>> matching;

        for (auto s : strs)
        {
            string tmp_str = s;
            sort(tmp_str.begin(), tmp_str.end());
            matching[tmp_str].push_back(s);
        }

        auto map_iter = matching.begin();
        while (map_iter != matching.end()) {
            out.push_back(map_iter->second);
            map_iter++;
        }
        return out;
    }
};

int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    auto ans = s.groupAnagrams(strs);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n ";
    }
    return 0;
}