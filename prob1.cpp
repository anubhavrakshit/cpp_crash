#include <iostream>
#include <cassert>
#include <vector>
#include <set>
using namespace std;

int total_aps(vector<vector<int>> &g) {
    int n{0};
    // r1 
    if ( (g[1][2] - g[1][1]) == (g[1][1] - g[1][0])) {
        //cout << "r1" << endl;
        n++;
    }
    // c1
    if ((g[2][1] - g[1][1]) == (g[1][1] - g[0][1])) {
        //cout << "c1" << endl;
        n++;
    }
    // d1 
    if ((g[0][0] - g[1][1]) == (g[1][1] - g[2][2])) {
        //cout << "d1" << endl;
        n++;
    }
    // d2
    if ((g[0][2] - g[1][1]) == (g[1][1] - g[2][0])) {
        //cout << "d2" << endl;
        n++;
    }
    //cout << "total aps " << n << endl;
    return n;
}
int maxap(vector<vector<int>> &g) {
    set<int> tried;
    int fixed_aps{0};
    int ans{0};

    // find col 0
    if ( (g[2][0] - g[1][0]) == (g[1][0] - g[0][0])) {
        fixed_aps++;
    }
    // find col 2
    if ( (g[2][2] - g[1][2]) == (g[1][2] - g[0][2])) {
        fixed_aps++;
    }
    // find row 0
    if ( (g[0][2] - g[0][1]) == (g[0][1] - g[0][0])) {
        fixed_aps++;
    }
    // find row 2
    if ( (g[2][2] - g[2][1]) == (g[2][1] - g[2][0])) {
        fixed_aps++;
    }

    //cout << "Fixed " << fixed_aps << endl;
    // calc possibe val of g[1][1]
    // the max possible AP's would be if g[1][1] forms AP's across multiple row/col/diag

    // try with r1
    if (abs(g[1][0] - g[1][2]) % 2 == 0)
    {
        int d = (g[1][2] - g[1][0]) / 2;
        g[1][1] = g[1][0] + d;
        //cout << "g[1][1] = " << g[1][1] << endl;
        tried.insert(g[1][1]);
        ans = max(ans, fixed_aps + total_aps(g));
    }
    
    // try with c1
    if (abs(g[0][1] - g[2][1]) % 2 == 0)
    {
        int d = (g[2][1] - g[0][1]) / 2;
        g[1][1] = g[0][1] + d;
        if (tried.find(g[1][1]) == tried.end()) {
            //cout << "g[1][1] = " << g[1][1] << endl;
            tried.insert(g[1][1]);
            ans = max(ans, fixed_aps + total_aps(g));
        }
    }
    // try with d1
    if (abs(g[0][0] - g[2][2]) % 2 == 0)
    {
        int d = (g[2][2] - g[0][0]) / 2;
        g[1][1] = g[0][0] + d;
        if (tried.find(g[1][1]) == tried.end()) {
            //cout << "g[1][1] = " << g[1][1] << endl;
            tried.insert(g[1][1]);
            ans = max(ans, fixed_aps + total_aps(g));
        }
    }
    // try with d2
    if (abs(g[0][2] - g[2][0]) % 2 == 0)
    {
        int d = (g[2][0] - g[0][2]) / 2;
        g[1][1] = g[0][2] + d;
        if (tried.find(g[1][1]) == tried.end()) {
        //cout << "g[1][1] = " << g[1][1] << endl;
            tried.insert(g[1][1]);
            ans = max(ans, fixed_aps + total_aps(g));
        }
    }

   return ans;
}
int main() 
{
    int ntc{0};
    cin >> ntc;

    int c{1};
    while (ntc--) {
       vector<vector<int>> grid(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val{0};
                if (i == 1 && j == 1) {
                    continue;
                }
                cin >> val;
                grid[i][j] = val; 
            }
        }
        cout << "Case #" << c << ": " << maxap(grid) << endl;
        c++;
    }

    return 0; 
}