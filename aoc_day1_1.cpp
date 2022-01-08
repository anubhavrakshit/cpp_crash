#include <iostream>
using namespace std;

int main() {
        int prev_depth{-1};
        int count_inc{0};
        int cur_depth{0};
        while (cin >> cur_depth) {
            if (prev_depth != -1 && prev_depth < cur_depth) {
                  count_inc++;  
            }
            prev_depth = cur_depth;
        }
        cout << "Number of inc = " << count_inc << endl;
        return 0;
}