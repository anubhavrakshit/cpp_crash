#include <iostream>
#include <unordered_map>
using namespace std;


int get_square(int num)
{
    int sq = 0;

    while (num) {
        int least_d = num % 10;
        sq += (least_d * least_d);
        num /= 10;
    }

    return sq;    
}

int main()
{
    unordered_map<int,bool> map;
    int x = 21;
    int sq = 0;
    map.insert(make_pair(x, true));
    while (true) {
        sq = get_square(x);
        cout << "sq = " << sq << "\n";
        if (sq == 1) {
            cout << "MAGIC\n";
            return true;
        }

        if (sq == 0) {
            cout << "NOMAGIC\n";
         return false;  
        }
        
        // repeat number will lead to endless loop
        if (map.find(sq) != map.end()) {
            cout << sq <<" = NOMAGIC REPEAT\n";
            return false;
        }

        map.insert(make_pair(sq, true));
        x = sq;
    }

    return 0;
}
