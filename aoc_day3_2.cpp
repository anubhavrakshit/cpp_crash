#include <iostream>
#include <vector>
#include <string>
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

int count_maj_pos(vector<string> &data, int pos) {
    int ret {-1};

    int ones{0}, zeros{0};
    for (auto &d : data) {
        if (d[pos] == '0') {
            zeros++;
        } else if (d[pos] == '1') {
            ones++;
        }
    }

    if (zeros > ones) {
        ret = 0;
    } else if (ones > zeros) {
        ret = 1;
    }

    return ret;
}

vector<string> filter(vector<string> &data, char key, int pos) {
    vector<string> ans;
    for (auto &d : data) {
        if (d[pos] == key) {
            ans.push_back(d);
        }
    }

    return ans;
}

int main() {
    string bstring;
    vector<string> data;
    int width{0};
    while (cin >> bstring) {
        data.push_back(bstring);
        width = max (width, static_cast<int>(bstring.length()));
    }

    bool calc_ogr{true}, calc_csr{true};
    vector<string> ogr{data}, csr{data};
    for (int i = 0; i < width; i++) {

        // Filter O2 by maj 
        if (calc_ogr) {
            int maj = count_maj_pos(ogr, i);
            if (maj == 1 or maj == -1) {
                ogr = filter(ogr, '1', i);
            } else {
                ogr = filter(ogr, '0', i);
            }
            
            // Finished calc
            if (ogr.size() == 1) {
                calc_ogr = false;
            }
        }

        // Filter CO2 by minority
        if (calc_csr) {
            int maj = count_maj_pos(csr, i);
            if (maj == 1 or maj == -1) {
                // min is 0
                csr = filter(csr, '0', i);
            } else {
                // min is 1
                csr = filter(csr, '1', i);
            }
        }

        // Finished calc
        if (csr.size() == 1) {
            calc_csr = false;
        }
    }

    assert(ogr.size() == 1);
    assert(csr.size() == 1);

    int ans = conv_to_int(ogr[0]) * conv_to_int(csr[0]);
    cout << "LSR  = " << ans << endl;   
    return 0;
}