#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <map>
using namespace std;


int main() {
    string line;
    struct Note {
            vector<string> pattern;
            vector<string> output_val; 
    };

    vector<Note> notes;
    int ans{0}; 
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<string> patterns;
        vector<string> outputs;
        bool is_pattern{true};
        for (string p; ss >> p; ) {
            if (p == "|") {
                is_pattern = false;
                continue;
            }

            if (is_pattern) {
                patterns.push_back(p);
                cout << "pat" << p << endl;
            } else {
                outputs.push_back(p);
                auto p_len = p.length();
                if (p_len == 2 or p_len == 4 or p_len == 3 or p_len == 7) {
                    ans++;
                }
                cout << "out" << p << endl;
            }
        }
        assert(patterns.size() == 10);
        assert(outputs.size() == 4);
        notes.push_back({patterns, outputs});
    }

    cout << "Ans: " << ans << endl;
    return 0;
}