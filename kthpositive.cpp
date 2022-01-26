#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int> &arr, int k) {
    int missing_count{0};
    // We use a two pointer method
    // Our aim is to count all missing numbers
    // i will be all possible strictly increasing numbers
    // j will track the numbers present in input array
    // TC: O(n) SC: O(1)
    int i{1}, j{0};
    for (; missing_count < k; i++) {
        // If j is in bounds only then increment to next position
        if (j < arr.size() and i == arr[j]) {
            j++;
        } else {
            missing_count++;
        }
    }

    return --i;
}