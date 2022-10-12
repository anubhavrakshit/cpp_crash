#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N; // Num Fabric
    vector<pair<string, int>> fabrics(N);
    vector<pair<int, int>> durablity(N);
    vector<int> uid(N);

    for (int i = 0; i < N; i++) {
        int d;
        string col;
        cin >> col >> d >> uid[i];
        fabrics[i] = {col, uid[i]};
        durablity[i] = {d, uid[i]};
    }
    
    sort(fabrics.begin(), fabrics.end());
    sort(durablity.begin(), durablity.end());

    int ans{0};
    for (int i = 0; i < N; i++) {
        if (fabrics[i].second == durablity[i].second) {
            ans++;
        }
    }
    cout << "Case #" << testCase << ": ";
    cout << ans;
    cout << endl;
  }
  return 0;
}
