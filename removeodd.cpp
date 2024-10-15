#include <iostream>
#include <queue>
#include <cassert>
#include <algorithm>

using namespace std;
vector<int> select_even(vector<int> cur) {
    if (cur.size() == 1) {
        return cur;
    }
    vector<int> selected;
    for (int i = 1; i <= cur.size(); i++) {
        if (i % 2) {
            continue;
        } else {
            selected.push_back(cur[i- 1]);
        }
    }
    return selected;
}

int main() {
    #if 0
    vector<int>  q;
    for (int i = 1; i <= 10; i++) {
        q.push_back(i);
    }
    while (q.size() > 1) {
        q = select_even(q);
        for_each(q.begin(), q.end(), [](auto n) {cout << n << ",";} );
        cout << endl;
    }
    cout << q.front();
    #endif
    auto matrix = std::vector<vector<int>>{10, vector<int>(10)};
    for (auto row: matrix) {
        for (auto i : row) {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
    
    return 0;
}