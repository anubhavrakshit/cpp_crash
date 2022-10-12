#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
using namespace std;


string feed_dogs(int n, int d, int c, int m, string &animals) {
    int i;
    //cout << n << " : " << d << " : " << c <<  " : " << m << endl; 
    for (i = 0; i < animals.length(); i++) {
        if (animals[i] == 'C') {
            if (c > 0) {
                c--;
            } else {
                //cout << "Not enough cat" << endl; 
                break;
            }
        } else {
            if (d > 0) {
                d--;
                c += m;
            } else {
                //cout << "Not enough dog" << endl; 
                break;
            }
        }
       
    }

    for (int j = i; j < animals.length(); j++) {
        if (animals[j] == 'D')
        {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int ntc{0};
    cin >> ntc;
    int tc{1};

    while (ntc--) {
        int n, d, c, m;
        cin >> n >> d >> c >> m;
        string animals;
        cin >> animals; 
        assert(animals.length() == n);        
        string ret = feed_dogs(n, d, c, m, animals);
        cout << "Case #" << tc << ": " << ret << endl;
        tc++;
    }
    return 0;
}