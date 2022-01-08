#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;
unsigned int conv_to_int(string &s) {
    unsigned int ans{0};

    for (auto &c : s) {
        ans <<= 1;
        if (c == '1') {
            ans += 1;
        }
    }
    return ans;
}

int main() {
    string bstring;
    unordered_map<int, int> fc_one, fc_zero;
    int width{0};
    while (cin >> bstring) {
        int bit_pos = 1;
        for (auto &c : bstring) {
            if (c == '0') {
                fc_zero[bit_pos]++;
            } else {
                fc_one[bit_pos]++;
            }
            bit_pos++;
        }
        width = max (width, bit_pos);
    }

    // Now find Gamma and Epsilon
    string  gamma, epsilon;
    for (int j = 1; j < width; j++) {
        if (fc_one[j] > fc_zero[j]) {
            gamma += '1';
            epsilon += '0';
        } else {
            gamma += '0';
            epsilon += '1';
        }
    }

    auto gm = conv_to_int(gamma);
    auto ep = conv_to_int(epsilon);

    cout << "ans = " << (gm * ep) << endl;
    return 0;
}