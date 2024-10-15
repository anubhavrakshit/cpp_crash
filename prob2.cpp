#include <iostream>
#include <cassert>
#include <vector>
#include <set>
using namespace std;


int find_maxi(vector<int> &L, vector<int> &R, int num_cuts) {

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int l_max{0}, l_indx{0};
    for (auto l : L) {
        cout << l << " ";
    }
    cout << endl;
     for (auto r : R) {
        cout << r << " ";
    }
    cout << endl;
    for (int i = 0; i < L.size(); i++) {
            auto u = upper_bound(R.begin(), R.end(), L[i]);
            if (u == R.begin()) {
                continue;
            }
            int num_ovrlp = R.end() - u;
            if (num_ovrlp > l_max)
            {
                l_max = num_ovrlp;
                l_indx = i;
            }
    }
    int r_max{0}, r_indx{0};
    for (int i = 0; i < R.size(); i++) {
            auto l = lower_bound(L.begin(), L.end(), R[i] - 1);
            if (*l > R[i]) {
                continue;
            }
            int num_ovrlp = l - L.begin();
            if (num_ovrlp > r_max)
            {
                r_max = num_ovrlp;
                r_indx = i;
            }
    }

    cout << "l_max=" << l_max << " l_indx=" << l_indx << endl; 
    cout << "r_max=" << r_max << " r_indx=" << r_indx << endl; 
    return 0;
}
int main() 
{
    int ntc{0};
    cin >> ntc;

    int c{1};
    while (ntc--)
    {
        vector<int> L;
        vector<int> R;
        int num_int;
        int num_cuts;
        cin >> num_int >> num_cuts;
        for (int i = 0; i < num_int; i++) {
            int li, ri;
            cin >> li >> ri;
            L.push_back(li);
            R.push_back(ri);
        }
        int ans = find_maxi(L, R, num_cuts);
        cout << "Case #" << c << ": " << ans << endl;
        c++;
    }

    return 0; 
}