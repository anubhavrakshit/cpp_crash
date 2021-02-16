#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Sword represents the position of the person holding the sword in the circle
// Time Complexity O(n) {n + n/2 + n/4 ....+ 1} | Space Complexity O(n)
int lastAlive(vector<int> &circle, int sword) {
    // Base condition: If a single person is alive we must stop recursion
    if (circle.size() == 1) {
        return circle[0];
    }

    cout << "Sword with pos = " << sword << " person = " << circle[sword] << endl;
    // kill the next guy from sword holder
    int pos_next = (sword + 1) % circle.size();
    cout << "Killed pos = " << pos_next << " person = " << circle[pos_next] << endl;
    // kill the next guy from sword holder
    circle.erase(circle.begin() + pos_next);

    return lastAlive(circle, pos_next);
}


int main() {
    cout << "Num people = ";
    int num_people;
    cin >>  num_people;
    cout << "Total num people = " << num_people << endl;
    
    // Fill circle with people represented as 1..num_people
    // Use modulo arithmetic to pretend that vector is circular
    vector<int> circle(num_people);
    for (int i = 0; i < num_people; i++) {
        circle[i] = i + 1;
    }

    // Its always the 1st person(0th index) who gets the sword
    int last_person = lastAlive(circle, 0);
    cout << "Last alive person = " << last_person << endl;
    
    return 0;
}