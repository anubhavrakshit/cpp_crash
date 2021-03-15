#include <iostream>
#include <vector>
#include <map>
using namespace std;

int dfs(vector<vector<int>> &arr, map<pair<int, int>, int> &memo, int r, int c)
{
    int num_rows = arr.size();
    int num_cols = arr[0].size();
    if (r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
        return 0;
    }
    if (r == num_rows - 1 && c == num_cols - 1) {
        return 1;
    }

    if (memo.find({r, c}) != memo.end()) {
        cout << "Memo at r " << r << " c " << c << endl;
        return memo.at({r, c});
    }

    // find nbrs of r, c and explore
    int right_r = r, right_c = c + 1;
    int down_r = r + 1, down_c = c;

    int paths = dfs(arr, memo, right_r, right_c) + dfs(arr, memo, down_r, down_c);

    memo[{r , c}] = paths; 
    return paths;
}

#if 0
int dfs_path( vector<vector<int> > &arr, int r, int c) {
    return 0;
}
#endif
int main()
{
    int dim = 5;
    vector<vector<int>> arr(dim, vector<int>(dim));

    int count = 1;
    map<pair<int, int> , int>  memo;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            arr[i][j] = count++;
        }
    }

    int res = dfs(arr, memo, 0, 0);
    cout << "paths = " << res << endl;
    return 0;
}

/*
1 2 3
4 5 6
7 8 9

    (0,0)
     /     \
  (1,0)    (0, 1) 
  /   \      /   \ 
null  (1,1) (1,1) (0, 2)

*/
