#include <iostream>
#include <string>
#include <deque>
using namespace std;

void permute(string& input, string& choosen) {
    if (input.length() == 0) {
        cout << choosen << endl;
        return;
    }

    for (int i = 0; i < input.length(); i++) {
        // choose 
        auto ch = input[i];
        //cout << "Chose = " << ch << endl;
        input.erase(input.begin() + i);
        //cout << "After erase = " << input << endl;
        choosen += ch;
        permute(input, choosen);
        choosen.pop_back();
        input.insert(i, 1, ch);
    }
}

int main() {
    string input{"ABCDEFGHIJKL"};
    string chosen;
    permute(input, chosen);
    return 0; 
}
