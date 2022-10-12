#include <iostream>
using namespace std;

int bot_score(int n) {
    int points{0};
    
    bool bot_turn{true};
    for (int i = 1; i <= n;) {
        if (bot_turn) {
            points++;
            bot_turn = false;
            if (i + 3 < n) {
                i += 3;
            } else {
                i += 2;
            }
        } else {
            bot_turn = true;
            i += 2;
        }
    }

    return points;
}

int main() {
    int ntc{0};
    cin >> ntc;
    int tc{1};

    while (ntc--) {
        int n;
        cin >> n;
        int ret = bot_score(n);
        cout << "Case #" << tc << ": " << ret << endl;
        tc++;
    }
    return 0;
}