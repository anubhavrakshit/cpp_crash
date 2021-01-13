#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

static int hit;
// Use recursion:
// Base Cases:
// 1. gridTraveller(1, 1) - 1 way
// 2. gridTraveller(0, n) - 0 way
// Normal Case:
// Go down/right and reduce the grid
int gridTraveller(int m, int n, unordered_map<string, int>& map) {
    if (m == 1 && n == 1) {
        return 1;
    } 
    if (m == 0 || n == 0) {
        return 0;
    }
    
    string key = to_string(m) + ":" + to_string(n);
    if (map[key]) {
        hit++;
        cout << "Found key " << key << endl;
        return map[key];
    }

    map[key] = gridTraveller(m - 1, n, map) + gridTraveller(m, n - 1, map);
    return map[key];
}


int main() {
    int m{14}, n{10};
    unordered_map<string, int> map;

    cout << "Num of ways to travel = " << gridTraveller(m, n, map) << "\n" << "Cache Hits" << hit << endl;
    return 0;   
}