#include <iostream>
#include <string>

using namespace std;

string intToBinary(int n) {
    if (n == 0) {
        return "";
    }

    string res = intToBinary(n / 2);
    res = res + to_string(n % 2);
    return res;
}

int main() {
    intToBinary(23); 
    return 0;
}