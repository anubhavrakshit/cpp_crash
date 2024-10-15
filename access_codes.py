from fractions import Fraction
from operator import is_
import math
import sys

def solution1(codes):
    count = 0
    for i in range(0, len(codes) - 2):
        x = codes[i]
        for j in  range(i + 1, len(codes) - 1):
            y = codes[j]
            if (y % x == 0):
                for k in range(j + 1, len(codes)):
                    z = codes[k]
                    if (z % y == 0):
                        count = count + 1
                        print("cand: ",x, y, z)

    return count

def solution(codes):
    ans = 0
    #possible mid element
    for i in range(1, len(codes) - 1):
        #find all divisors of mid element
        y = codes[i]
        #print("mid = ", y)
        num_div = 0
        for j in range(0, i):
            x = codes[j]
            if (y % x == 0):
                num_div = num_div + 1
        num_mult = 0
        for k in range(i + 1, len(codes)):
            z = codes[k]
            if (z % y == 0):
                num_mult = num_mult + 1
        
        #print("num div", num_div)
        #print("num mult", num_mult)
        ans = ans + num_div * num_mult
    return ans

def main():
    print(solution1([1,2,3,3,4,4,5,6])) 
    print(solution([1,2,3,3,4,4,5,6])) 
    print(solution1([1,1,1])) 
    print(solution([1,1,1])) 
if __name__ == "__main__":
    main()