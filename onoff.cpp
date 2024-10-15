#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int tc{0};
    cin >> tc;
    while (tc--) {
        int N, K;
        cin >> N >> K;
        if (N % 4 == 0) {
            // Return to same position
            if (K == 1) {
                cout << "On\n";
            } else {
                cout << "Off\n";
            }
        } else {
            // Flip from Off to On
            if (K == 0) {
                cout << "On" << endl;
            } else {
                cout << "Ambiguous" << endl;
            }
        }
    }
	return 0;
}
