#include <iostream>
#include <vector>
using namespace std;

int num_rb(vector<int>& visitors) {
    int ans{0};
    int maxi {-1};

    for (int i = 0; i < visitors.size() - 1; i++) {
        int nv = visitors[i];
        if (nv > maxi) {
            maxi = nv;
            if (nv > visitors[i + 1]) {
                ans++;
            }
        }
    }

    if (visitors[visitors.size() - 1] > maxi) {
        ans++;
    }

    return ans;
}

int main() {
    int ntc{0};
    cin >> ntc;
    int tc{1};

    while (ntc--) {
        int N;
        cin >> N;
        vector<int> visitors;
        while (N--) {
            int nv{0};
            cin >> nv;
            visitors.push_back(nv);
        }
        int ret = num_rb(visitors);
        cout << "Case #" << tc << ": " << ret << endl;
        tc++;
    }
    return 0;
}