#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;

ll my_pow(int x, int y) {
    if (y == 0) {return 1;}
    ll ans = x;
    while (--y) {
        ans *= ans;
    }

    return ans;
}
int CountNumberOfPairs(int a, int b, ll n, int k) {
  // TODO: implement this method to determine the number of pairs modulo 10^9+7
  int number_of_pairs = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }

      if ((my_pow(i, a) + my_pow(j, b)) % k == 0) {
        //cout << i << " " << j << endl;
        number_of_pairs++;
      }

    }
  }
  int modulo = 10^9 + 7;
  return number_of_pairs % modulo;
}

int main() {
  int test_case_count;
  cin >> test_case_count;
  int a, b, k;
  ll n;

  for (int tc = 1; tc <= test_case_count; ++tc) {
    cin >> a >> b >> n >> k;
    cout << "Case #" << tc << ": " << CountNumberOfPairs(a, b, n, k) << "\n";
  }
  return 0;
}
