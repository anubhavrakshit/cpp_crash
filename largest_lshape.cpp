#include <iostream>
#include <string>
using namespace std;

int main() {
    int num_tc; cin >> num_tc;
    int tc{1};

    while (num_tc--) {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                string line;
                getline(cin, line);
                stringstream ss(line);
                for (int k; ss >> k;) {
                    grid[i][j] = k;
                }       
            }
        }

        
    }
}