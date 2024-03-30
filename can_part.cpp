using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
  virtual bool canPartition(const vector<int> &num, int sum) {
    // TODO: Write your code here
    int n = num.size();
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = false;
        }
    }

    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        dp[i][j] = dp[i - 1][j] == true ? true : false;
        if (num[i] <= j) {
          dp[i][j] =  dp[i][j] || dp[i - 1][j - num[i]];
        }

      }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}