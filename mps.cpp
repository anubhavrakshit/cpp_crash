#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {

    int mps{0}; // max path sum
    
    int na = A.size() , nb = B.size(); // num elems in A and B
    int psa{0}, psb{0}; // rolling path sums
    
    
    int i{0}, j{0}; // two ptrs
    while ((i < na) && (j < nb)) {
        //cout << "psa = " << psa << " psb = " << psb << " mps = " << mps << endl;
        if (A[i] < B[j]) {
            psa += A[i++]; // update path sum and bump pointer
        } else if (A[i] == B[j]) {
            // add the max local path so far to mps
            mps += max(psa, psb);
            //cout << "psa = " << psa << " psb = " << psb << " mps = " << mps << endl;
            // junction reset sums
            psa = psb = 0;
            // move forward and update path sums we need to account for the junction point
            if (i < na) {
                psa += A[i++];
            }
            if (j < nb) {
                psb += B[j++];
            }
        } else {
            psb += B[j++];
        }
        
    }
    
    // in case of differing lengths we have to account for trailing elements
    while (i < na){
        assert(i < na);
        psa += A[i++];
    }
     
    while (j < nb){
        assert(j < nb);
        psb += B[j++];
    }
    
    // this will also take care of no junction case
    mps += max(psa, psb);
    
    return mps;
}

int main() {
    vector<int> A {2, 3, 7, 10, 12};
    vector<int> B {1, 5, 7, 8};

    cout << "res = " << solve(A, B) << endl;
    return 0;
}