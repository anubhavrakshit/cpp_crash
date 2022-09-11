#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <set>
#include <map>
using namespace std;

int main() {
    string line;
    struct Note {
            vector<string> pattern;
            vector<string> output_val; 
    };

    vector<Note> notes;
    int total_ans{0};
    while (getline(cin, line)) {
        stringstream ss(line);
        int ans{0}; 
        vector<string> patterns;
        vector<string> outputs;
        bool is_pattern{true};
        map<string, int> map;
        for (string p; ss >> p; ) {
            if (p == "|") {
                is_pattern = false;
                // Create map from patterns
                string eight;
                string one;
                string seven;
                string four;
                for (auto& s : patterns) {
                    if (s.length() == 2) {
                        map[s] = 1;
                        one = s;
                    } else if (s.length() == 4) {
                        map[s] = 4;
                        four = s;
                    } else if (s.length() == 3) {
                        map[s] = 7;
                        seven = s;
                    } else if (s.length() == 7) {
                        map[s] = 8;
                        eight = s;
                    }
                }
                
                set<char> seven_four;
                for (auto c : seven) {
                    seven_four.insert(c);
                }
                for (auto c : four) {
                    seven_four.insert(c);
                }

                // find string representing 9 
                char last_seg;
                string nine;
                for (auto& s : patterns) {
                    if (s.length() != 6) {
                        continue;
                    }

                    // possible 9 
                    // 7 + 4 + ? will give us 9
                    // so only one mismatch
                    char mismatch;
                    int num_mismatch{0};
                    for (auto c : s) {
                        if (seven_four.count(c) == 0) {
                            mismatch = c;
                            num_mismatch++;
                        }

                        if (num_mismatch > 1) {
                            break;
                        }
                    }

                    if (num_mismatch == 1) {
                        map[s] = 9;
                        nine = s;
                        last_seg = mismatch;
                        break;
                    }
                }
                set<char> nine_set;
                for (auto c : nine) {
                    nine_set.insert(c);
                }
                char left_bottom;
                for (auto c : eight) {
                    if (nine_set.count(c) == 0) {
                        left_bottom = c;
                    }
                }

                // Find 0: will always intersect with Segments making 1                
                for (auto& s : patterns) {
                    if (s.length() != 6 || map.find(s) != map.end()) {
                        continue;
                    }

                    set<char> pos_zero;
                    for (auto c : s) {
                        pos_zero.insert(c);
                    }

                    bool found = true;
                    for (auto c : one) {
                        if (pos_zero.count(c) != 1) {
                            found = false;
                            break;
                        } 
                    }

                    if (found) {
                        map[s] = 0;
                        break;
                    }                   
                }

                // Find 6
                for (auto& s : patterns) {
                    if (s.length() != 6) {
                        continue;
                    }

                    if (map.find(s) != map.end()) {
                        continue;
                    }
                    map[s] = 6;
                    break;
                 }

                 // Find 3: Only number with 5 segment that intersects with 1
                for (auto &s : patterns) {
                    if (s.length() != 5) {
                        continue;
                    }

                    set<char> pos_three;
                    for (auto c : s) {
                        pos_three.insert(c);
                    }
                    
                    bool found = true;
                    for (auto c : one) {
                        if (pos_three.count(c) != 1) {
                            found = false;
                            break;
                        }
                    }

                    if (found) {
                        map[s] = 3;
                        break;
                    }
                }

                // Find 2
                for (auto &s : patterns) {
                    if (s.length() != 5) {
                        continue;
                    }

                    if (map.find(s) != map.end()) {
                        continue;
                    }

                    set<char> pos_two;
                    for (auto c : s) {
                        pos_two.insert(c);
                    }
                    
                    bool found = false;
                    if (pos_two.count(left_bottom) == 1) {
                            found = true;
                    }

                    if (found) {
                        map[s] = 2;
                        break;
                    }
                }

                // Find 5 
                for (auto &s : patterns) {
                    if (s.length() != 5) {
                        continue;
                    }

                    if (map[s] == 3 || map[s] == 2) {
                        continue;
                    }

                    map[s] = 5;
               }

                continue;
            }

            sort(p.begin(), p.end());
            if (is_pattern) {
                patterns.push_back(p);
            } else {
                outputs.push_back(p);
                ans = 10 * ans + map[p];
            }
        }
        assert(patterns.size() == 10);
        assert(outputs.size() == 4);
        total_ans += ans;
    }

    cout << "Ans: " << total_ans << endl;
    return 0;
}