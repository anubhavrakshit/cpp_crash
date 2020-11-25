#include <iostream>

using namespace std;

void hanoi_helper(int n, int start, int end) {
    // 0 1 2
    auto get_third = [](int start, int end) {return 3 - (start + end);};

    if (n == 0) {
        return;
    }

    int third = get_third(start, end);
    hanoi_helper(n - 1, start, third);
    cout << "Move disc " << n << " from " << start << " to " << end << endl;
    hanoi_helper(n - 1, third, end);
}

void hanoi(int n) {
    int start{0};
    int end{2};
    hanoi_helper(n, start, end);
}
int main() {
    int num_discs{2};
    hanoi(num_discs);

    return 0;
}