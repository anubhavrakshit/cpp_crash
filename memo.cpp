#include <iostream>
#include <vector>

using namespace std;
int fact (int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= 1;
    }
    return ans;
}

int ncr(int n, int r) {
    if (n == r ) {
        return 1;
    }
    if (r == 0 and n != 0) {
        return 1;
    }
    return fact(n) / (fact(n - r) * fact(r));
}

int ways(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 or n == 2) {
        return 1;
    }

    int h = log2(n);
    int x = pow(2, h) - 1;
    int l = (x - 1) / 2 + min(n - x, (x + 1)/2 );
    int r = n - 1 - L;
    return ncr(n - 1, l) * ways(l) * ways(r);
}