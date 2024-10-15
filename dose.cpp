#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t{0};
    cin >> t;
	while (t--) {
	    int D, L, R;
	    cin >> D >> L >> R;
	    if (D >= L and D <= R) {
	        cout << "Take second dose now" << endl;
	    } else if (D < L) {
	        cout << "Too Early" << endl;
	    } else {
	        cout << "Too Late" << endl;
	    }
	}
	return 0;
}
