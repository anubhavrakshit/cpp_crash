#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    void hlpr(vector<vector<int>> &image, vector<vector<bool>> &visit, int sr, int sc, int oldColor, int newColor)
    {
        vector<pair<int, int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        const auto W = image[0].size();
        const auto H = image.size();
        auto is_valid = [&](int r, int c) { return (r >= 0 && r < H && c >= 0 && c < W); };

        // start color
        assert(is_valid(sr, sc));
        if (visit[sr][sc])
        {
            return;
        }

        visit[sr][sc] = true;
        for (auto con : dir)
        {
            int temp_r = sr + con.first;
            int temp_c = sc + con.second;
            if (is_valid(temp_r, temp_c) && image[temp_r][temp_c] == oldColor)
            {
                hlpr(image, visit, temp_r, temp_c, oldColor, newColor);
                visit[temp_r][temp_c] = true;
                ;
            }
        }
        image[sr][sc] = newColor;

        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        const auto W = image[0].size();
        const auto H = image.size();
        vector<vector<bool>> visit(H, vector<bool>(W, false));
        int oldColor = image[sr][sc];
        hlpr(image, visit, sr, sc, oldColor, newColor);

        return image;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr{1}, sc{1}, newColor{2};
    auto result = s.floodFill(image, sr, sc, newColor);

    return 0;
}