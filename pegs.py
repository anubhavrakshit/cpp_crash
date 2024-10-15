from fractions import Fraction
from operator import is_
import sys

def pegs(arr):
    # min radius is 1
    if (len(arr) < 2):
        return [-1, -1]
    #print("input ", arr) 
    for i in range(len(arr)):
        if (i > 0):
            if (arr[i] < 0):
                return [-1, -1]
            if (arr[i] - arr[i - 1] < 2):
                return [-1, -1]

    is_even = (len(arr) % 2 == 0)
    total = arr[-1] - arr[0]
    rad = 2 * total
    ans = [-1, -1]
    if (is_even):
        for i in range(len(arr)):
            if (i > 0 and (i % 2 == 0)):
                rad = rad - (4 * (arr[i] - arr[i - 1]))

        if (rad % 3 == 0):
            ans = [rad // 3, 1]
        else:
            ans = [rad , 3]
    else:
        for i in range(len(arr)):
            if (i > 0 and (i % 2 == 0)):
                rad = rad - (4 * (arr[i] - arr[i - 1]))
        
        ans = [rad, 1]

    cur_rad = ans[0] / ans[1]
    for i in range(len(arr)):
        if (i == 0):
            if (cur_rad < 1):
                return [-1, -1]
            continue
        if (cur_rad < 1):
            return [-1, -1]
        cur_rad = (arr[i] - arr[i - 1]) - cur_rad

    return ans

def main():
    print(pegs([4, 17, 50]))
    print(pegs([4, 30, 50])) 
    print(pegs([1, 51]))
    print(pegs([1, 31]))
    print(pegs([1, 31, 51, 71]))
    print(pegs([1, 31, 51, 71, 91]))
    print(pegs([8, 10, 51, 71, 90]))
    print(pegs([104, 117, 150]))
    print(pegs([4, 9, 17, 31, 40]))
    print(pegs([4, 9, 17, 31, 40, 44]))
    print(pegs([4, 6, 17, 31, 40, 44]))

if __name__ == "__main__":
    main()
