#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


string solve(string A) {
    stack<char> st;

    unordered_map<char, int> prec;
    prec['+'] = 0;
    prec['-'] = 0;
    prec ['/'] = 1;
    prec['*'] = 1;
    prec['^'] = 2;

    string ans;
    for (char c : A) {
        if (c >= 'a' and c <= 'z') {
            cout << c << ":1\n";
            ans += c;
        } else if (c == '(') {
            cout << c << ":2\n";
            st.push(c);
        } else if (c == ')') {
            while (st.top() != '(') {
                ans += st.top();
                cout << st.top() << ":3\n";
                st.pop();
            }
            assert(st.top() == '(');
            st.pop();
        } else {
            cout << "Operator\n";
            if (!st.empty() and st.top() == '(') {
                cout << c << ":4\n";
                st.push(c);              
            } else {
                while (!st.empty() and st.top() != '(' and (prec[st.top()] >= prec[c])) {
                    ans += st.top();
                    cout << st.top() << ":5\n";
                    st.pop();
                }
                st.push(c);
                cout << c << ":6\n";
            }
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}


int main() {
    cout << solve("d-(y*q+k)-u-(w-d^x)-p/(u-o)/o/(q*l)");
    return 0;
}