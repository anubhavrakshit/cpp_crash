class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      // Perform BFS and find the shortest path to exit
      // Exit is empty cell in border
      // i == 0 or i == max_row - 1
      // j == 0 or j == max_col - 1

      auto max_rows = maze.size();
      auto max_cols = maze[0].size();
      auto is_exit = [&](int i, int j) {
        if (i == entrance[0] and j == entrance[1]) {
          return false;
        }
        return (maze[i][j] == '.') and (i == 0 or i == max_rows - 1 or j == 0 or j == max_cols - 1);
      };
       auto is_valid = [&](int i, int j) {
        return (i >= 0 and i < max_rows  and j >= 0 and j < max_cols) and (maze[i][j] == '.');
      };

      // Start BFS from entrance 
      vector<pair<int, int>> dirs = {{1,0} , {-1, 0}, {0, 1}, {0, -1}};
      queue<pair<int, int>> q;
      q.push({entrance[0], entrance[1]});
      vector<vector<int> >visit(max_rows, vector<int>(max_cols, 0));
      int dist{0};
      while (!q.empty()) {
        auto level_size = q.size();
        while (level_size--) { 
          auto u = q.front();
          q.pop();
          //cout << u.first << "," << u.second << endl;
          visit[u.first][u.second] = 1;
          if (is_exit(u.first, u.second)) {
            return dist;
          }
          for (auto dir : dirs) {
            pair<int, int> next_pos = {u.first + dir.first, u.second + dir.second};
            if (is_valid(next_pos.first, next_pos.second) and !visit[next_pos.first][next_pos.second]) {
              visit[next_pos.first][next_pos.second] = 1;
              q.push(next_pos);
            }
          }
        }
        dist++;
      }
      return -1; 
    }
};