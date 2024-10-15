#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

struct hash_fn {
    size_t operator () (const pair<int, int> &x) const {
        return x.first ^ x.second;
    }
};

pair<int, int> find_dest(int N, int R, int C, int SR, int SC, string& cmd) {
    // Visited  grid[x][y] = 1 
    unordered_set< pair<int, int>, hash_fn> visited;

    map<char, pair<int, int>> dir;
    dir['N'] = {-1, 0};
    dir['S'] = {1, 0};
    dir['E'] = {0, 1};
    dir['W'] = {0, -1};

    visited.insert({SR, SC});
    int cur_r = SR, cur_c = SC;
    // Parse command and move 
    for (int i = 0; i < cmd.length(); i++) {
        char d = cmd[i];

        // find next unvisited pos
        while (visited.find({cur_r, cur_c}) != visited.end()) {
            cur_r += dir[d].first;
            cur_c += `dir[d].second;
        }
        // mark as visited
        visited.insert({cur_r, cur_c});
    }

    return {cur_r, cur_c};
}

int main() {
    int ntc{0};
    cin >> ntc;
    int tc{1};

    while (ntc--) {
        int N, R, C, SR, SC;
        string cmd;
        cin >> N >> R >> C >> SR >> SC >> cmd;
        pair<int, int> ans = find_dest(N, R, C, SR, SC, cmd);
        cout << "Case #" << tc << ": " << ans.first << " " << ans.second << endl;
        tc++;
    }
    return 0;
}