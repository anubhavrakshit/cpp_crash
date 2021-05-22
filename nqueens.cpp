#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isSafe(int row, int col, unordered_map<int, bool> &col_m,
unordered_map<int, bool> &diag1_m,
unordered_map<int, bool> &diag2_m) {
    if (col_m[col] || diag1_m[col - row] || diag2_m[row + col]) {
        return false;
    }
    
    return true;
}
void place(vector<string> &b, int row, int remain, unordered_map<int, bool> &col_m,
unordered_map<int, bool> &diag1_m, unordered_map<int, bool> &diag2_m,
vector<vector<string> > &ans) {
    
    int A = b.size();
    if (row >= A) {
        if (!remain) {
            ans.push_back(b);
        }
        return;
    }
    
    // try all position in a row
    for (int col = 0; col < A; col++) {
        if (isSafe(row, col, col_m, diag1_m, diag2_m)) {
            #if 0
            // current board
            for (auto p: b) {
                cout << p << endl;
            }
            #endif
            // mark
            b[row][col] = 'Q';
            col_m[col] = true;
            diag1_m[col - row] = true;
            diag2_m[col + row] = true;
            // place the next queen
            place(b, row + 1, remain - 1, col_m, diag1_m, diag2_m, ans);
            // unmark
            b[row][col] = '.';
            col_m[col] = false;
            diag1_m[col - row] = false;
            diag2_m[col + row] = false;
        }
    }
    
    return;
}
    

vector<vector<string> > solveNQueens(int A) {
    vector<string> b(A, string(A, '.'));
    vector<vector<string> > ans;
    unordered_map<int, bool> col_m;
    unordered_map<int, bool> diag1_m;
    unordered_map<int, bool> diag2_m;
    int row{0}, col{0};
    int remain{A};
    place(b, row, remain, col_m, diag1_m, diag2_m, ans);
    
    return ans;
}

int main() {

        int i;
        cout << "Enter board size = ";
        cin >> i;

        vector<vector<string>> ans;
        ans = solveNQueens(i);

        if (!ans.empty()) {
            cout << "Ans for Board of size " << i << endl;
        }

        for (auto board : ans) {
            for (auto row : board) {
                    cout << row << endl;
            }
            cout << "--" << endl;
        }
    return 0;
}