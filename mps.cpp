#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {

    int mpsum{0}; // max path sum
    
    int na = A.size() , nb = B.size(); // num elems in A and B
    int psuma{0}, psumb{0}; // rolling path sums
    
    int i{0}, j{0}; // two ptrs
    while ((i < na) && (j < nb)) {
        if (A[i] < B[j]) {
            psuma += A[i++]; // update path sum and bump pointer
        } else if (A[i] == B[j]) {
            // add the max local path so far to mpsum
            mpsum += max(psuma, psumb);
            // at junction reset sums
            psuma = psumb = 0;
            // move forward and update path sums we need to account for the junction point
            psuma += A[i++];
            psumb += B[j++];
        } else {
            psumb += B[j++];
        }
    }
    
    // in case of differing lengths we have to account for trailing elements
    while (i < na){
        assert(i < na);
        psuma += A[i++];
    }
    while (j < nb){
        assert(j < nb);
        psumb += B[j++];
    }
    
    // this will also take care of no junction case
    mpsum += max(psuma, psumb);
    return mpsum;
}

int main() {
    vector<int> A {2, 3, 7, 10, 12};
    vector<int> B {1, 5, 7, 8};

    cout << "res = " << solve(A, B) << endl;
    return 0;
}