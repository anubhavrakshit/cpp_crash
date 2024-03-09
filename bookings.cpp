#include <iostream>
#include <vector>
#include <stack> 
using namespace std;
int solve(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int, int>> bookings;

    for (int i = 0; i < arrive.size(); i++) {
        bookings.push_back({arrive[i], depart[i]});
    }

    sort(bookings.begin(), bookings.end());
    stack<pair<int, int>> st;
    int nc{1};
    for (int i = 0; i < bookings.size(); i++) {
        cout << "Examine " << bookings[i].first << ":" << bookings[i].second << endl;  
        // No booking 
        if (st.empty()) {
            st.push(bookings[i]);
        } else {
            // Conflict booking
            if (st.top().second >= bookings[i].first) {
                pair<int, int> b = {bookings[i].first, max(st.top().second, bookings[i].second)};
                st.push(b);
                cout << "Conflict " << b.first << ":" << b.second << endl; 
            } else {

                while (!st.empty()) {
                    st.pop();
                }
            }
        }

        cout << "Num conflicts = " << st.size() << endl;
        if (st.size() > K) {
            return 0;
        }
    }
    return 1;
}
int main() {
    vector<int> arrive = {13, 14, 36, 19, 44, 1, 45, 4, 48, 23, 32, 16, 37, 44, 47, 28, 8, 47, 4, 31, 25, 48, 49, 12, 7, 8};
    vector<int> depart = {28, 27, 61, 34, 73, 18, 50, 5, 86, 28, 34, 32, 75, 45, 68, 65, 35, 91, 13, 76, 60, 90, 67, 22, 51, 53};
    int k = 23;
    solve(arrive, depart, k);
    return 0;
}