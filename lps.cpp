#include <iostream>
#include <vector>
#include <string>
using namespace std;

int hlpr(string& A, int i, int j, vector<vector<int>>& dp, pair<int, int> &lps) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    if (i == j) {
        dp[i][j] = 1;
        return dp[i][j];
    }
    
    if (i > j) {
        dp[i][j] = 0;
        return 0;
    }
    
    if (A[i] == A[j] && j - i == 1) {
        dp[i][j] = 2;
        return dp[i][j];
    }
    
    if (A[i] == A[j]) {
        int ps =  hlpr(A, i + 1, j - 1, dp, lps);
        // Only increase size if the internal sub string is also a palin
        dp[i][j] = ps > 0 ? 2 + ps : ps; 
    }
    else if (A[i] != A[j]) {
         dp[i][j] = 0;
    }
    
    // explore other possible palin
    dp[i][j - 1] = hlpr(A, i, j - 1, dp, lps);
    dp[i + 1][j] = hlpr(A, i + 1, j, dp, lps);
    
    // got a longer palin 
    if (dp[i][j] > (lps.second - lps.first + 1)) {
            lps.first = i;
            lps.second = j;
    } else if (dp[i][j] == (lps.second - lps.first + 1)) {
        // for same len prefer earlier palin
        if (i < lps.first) {
            lps.first = i;
            lps.second = j;
        }
    }
    return dp[i][j];
}


string solve(string A) {
    
    //vector<vector<int>> dp(l + 1, vector<int>(l + 1, -1));
    vector<vector<int>> dp(A.length() + 1, vector<int>(A.length() + 1, -1));
    
    // get the lps indices
    pair<int, int> lps{0, 0};
    hlpr(A, 0, A.length() - 1, dp, lps);
    
    string ans = string(A.begin() + lps.first, A.begin() + lps.second + 1);
    return ans;
}

int main() {
    cout << "Enter String: ";
    string A;
    cin >> A;

    cout << "lps = "<< solve(A) << endl;
    return 0;
}