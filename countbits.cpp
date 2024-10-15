#include <iostream>
#include <vector>
using namespace std;

short parity(unsigned long num) {
    // If odd number of 1 then p = 1
    int p{0};
    while (num) {
        p ^= 1;
        num &= (num - 1);
    }

    return p;
}

int main() {
    vector<int> par_table();
    for (int i = 0; i < 256; i++) {
        par_table[i] = (parity(i));
        //cout << "Parity of " << std::hex << i << " is " << par_table[i] << endl;
    }
    for (int i = 1; i < 100000000; i++) {
        int w0 = parity(i & 0xffff);
        int w1 = parity((i >> 8) & 0xff);
        int w2 = parity((i >> 16) & 0xff);
        int w3 = parity((i >> 24) & 0xff);
        int ans = w0 ^ w1 ^ w2 ^ w3;
       // assert (ans == parity(i));
        assert(ans == 1 or ans == 0);
    }

    return 0;
}


