#if 0
array [1 2 3]
       4 5 6
       7 8 9

1 2 3 6 9 8 7 4 5 
#endif

#include <iostream>
#include <vector>

using namespace std;

// O(n) | O(1)
void print_spiral(vector<vector<int> > arr) {
    int num_rows = arr.size();
    int num_cols = arr[0].size();
    int top_r = 0, right_c = num_cols - 1, bot_r = num_rows - 1, left_c = 0;
    
    while (top_r <= bot_r && left_c <= right_c) {
        // state machine right -> down -> left -> top

        // Go right top_r, col {left_c -> right_c}
        for (int j = left_c; j <= right_c; j++) {
            cout << arr[top_r][j] << " ";
        }
        cout << endl;
        top_r++;

        // Go down  {top_r -> bot_r} , right_c
        for (int i = top_r; i <= bot_r; i++) {
            cout << arr[i][right_c] << " ";
        }
        cout << endl;
        right_c--;

        // Go left bot_r, {right_c -> left_c}
        for (int j = right_c; j >= left_c; j--) {
            cout << arr[bot_r][j] << " ";
        }
        cout << endl;
        bot_r--;

        // go up bot_r->top_r , left_c
        for (int i = bot_r; i >= top_r; i--) {
            cout << arr[i][left_c] << " ";
        }
        cout << endl;
        left_c++;
    }
}


int main()
{
    vector<vector<int>> arr(3, vector<int>(3));

    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = count++;
        }
    }
    print_spiral(arr);

    return 0;
}