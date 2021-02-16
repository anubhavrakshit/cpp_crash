#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

void isort(vector<int>& arr) {
    int num_elems = arr.size();

    for (int i = 1; i < num_elems; i++) {
        int curIndex = i;
        int curVal = arr[curIndex];

        while (curIndex > 0 && curVal < arr[curIndex - 1]) {
            arr[curIndex] = arr[curIndex - 1];
            curIndex--;
        }

        arr[curIndex] = curVal;
    }
}

int main() {
    vector<int> arr;
    vector<int> sort_arr;

    for (int i = 0; i < 10000; i++) {
        int random = rand() % 10000;
        arr.push_back(random);
    } 
    sort_arr = arr;
    sort(sort_arr.begin(), sort_arr.end());
    isort(arr);
    assert(arr == sort_arr);
    
    arr.resize(0);
    sort_arr.resize(0);
    for (int i = 0; i < 10000; i++) {
        int random = rand() % 10000;
        arr.push_back(random);
    } 
    sort_arr = arr;
    sort(sort_arr.begin(), sort_arr.end());
    isort(arr);
    assert(arr == sort_arr);
    return 0;
}