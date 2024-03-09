#include <iostream>
using namespace std;

int main() {
    cout << "Enter num: ";
    int A;
    cin >> A;
    int l{0}, r{31};
    auto bit_swap = [&A](int l, int r) {
        int l_mask = (0x1 << l);
        int r_mask = (0x1 << r);

        if ((A & l_mask)!= 0 and (A & r_mask) == 0) {
            A ^= l_mask;
            A ^= r_mask;
            cout << "Swap " << l << "-" << r << endl;
        } else if ((A & l_mask)== 0 and (A & r_mask) != 0) {
            A ^= l_mask;
            A ^= r_mask;
            cout << "Swap " << l << "-" << r << endl;
        }
        return;
    };

    while (l < r) {
        bit_swap(l, r);
        l++;r--;
    }

    cout << "Ans " << A << endl;
}