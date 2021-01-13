#include <iostream>
#include <string>
using namespace std;


void Print(string choosen, string remain) {
    if (!remain.length()) {
        cout << choosen << endl;
    }

   // Each position can be filled by one of the chars in input
   // Rest of the positions also can be filled in the same way as
   // above 
    for (int i = 0; i < remain.length(); i++) {
        string c = choosen;
        // Pick up a char from remaining and add to choosen
        c += remain[i];
        string r = remain;
        r.erase(i, 1);
        Print(c, r);
    }

}
int main() {
    string ip;
    cout << "Enter string ";
    cin >> ip;

    Print("", ip);

    return 0;
}