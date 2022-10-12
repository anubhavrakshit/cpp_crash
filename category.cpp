#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double success(vector<double> &A, int n_reg, int m_cat) {
    sort(A.begin(), A.end(), greater<int>());
    double ans{0};
    int allot{0};
    for (int i = 0; i < m_cat - 1; i++, allot++) {
        ans += A[i];
    }

    int remain = n_reg - allot;
    int mid = remain / 2;
    if (remain % 2 == 0) {
        ans += (A[allot + mid - 1] + A[allot + mid]) / 2;
    } else {
        ans += A[allot + mid];
    }

    return ans;
}

int main()
{
    int num_tc;
    cin >> num_tc;
    for (int i = 0; i < num_tc; i++) {
        int n_reg, m_cat;
        cin >> n_reg >> m_cat;
        vector<double> A(n_reg, 0);
        for (int j = 0; j < n_reg; j++) {
            double n;
            cin >> n;
            A[j] = n; 
        }
        double ans = success(A, n_reg, m_cat);
        cout << "Case #" << i + 1 << ": "; 
        cout << fixed << setprecision(12);
        cout << ans << endl;
    }

    return 0;
}