#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

pair <long long, long long> hydrate(vector<pair<long long, long long>> &cordx, vector<pair<long long, long long>> &cordy) {
   sort(cordx.begin(), cordx.end());
   sort(cordy.begin(), cordy.end());

   // find median of x
   long long mid = (cordx.size() - 1) / 2;
   return {cordx[mid].first, cordy[mid].first};

}
int main() {
    long long ntc{0};
    cin >> ntc;
    long long tc{1};

    while (ntc--) {
        long long n;
        cin >> n;

        vector<pair<long long, long long>> cordx;
        vector<pair<long long, long long>> cordy;
        for (long long i = 0; i < n; i++) {
            long long x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cordx.push_back({x1, y1});
            cordx.push_back({x2, y2});
            cordy.push_back({y1, x1});
            cordy.push_back({y2, x2});
        }
        pair<long long, long long> ret = hydrate(cordx, cordy);
        cout << "Case #" << tc << ": " << ret.first << " "  << ret.second << endl;
        tc++;
    }
    return 0;
}