from fractions import Fraction
from operator import is_
import math
import sys
def solution1(x, y):
    memo = {}
    def hlpr(x, y, t_x, t_y, g):
        #print("Input = ", f)
        if (x == t_x and y == t_y):
            return g

        if (x > t_x or y > t_y):
            return -1

        key1 = str(x) + str(y)
        key2 = str(y) + str(x)
        if (key1 in memo):
            #print("Cache Hit!")
            return memo[key1]
        if (key2 in memo):
            #print("Cache Hit!")
            return memo[key2]
        
        ans = 0
        ans = hlpr(x, x + y, t_x, t_y, g + 1)
        key = str(x) + str(x + y)
        memo[key] = ans
        if (ans != -1):
            return ans
        ans = hlpr(x + y, y, t_x, t_y, g + 1)
        key = str(x + y) + str(y)
        memo[key] = ans
        return ans
    
    num_gen = hlpr(1, 1, int(x), int(y), 0)
    if (num_gen == -1):
        return 'impossible'
    return str(num_gen)

def solution(a, b):
    x = int(a)
    y = int(b)
    if (x < 1 or y < 1):
        return 'impossible'
    
    gen = 0
    while (True):
        if (x == 1 and y == 1):
            break
        elif (x < 1 or y < 1):
            return 'impossible'
        elif (x > y):
            if (y == 1):
                gen = gen + x - y
                break
            temp_steps = x // y 
            x = x - (y * temp_steps)
            gen = gen + temp_steps
        else:
            if (x == 1):
                gen = gen + y - x
                break
            temp_steps = y // x 
            y = y - (x * temp_steps)
            gen = gen + temp_steps
    
    return str(gen)

def main():
    print(solution(4, 7)) 
    print(solution(2, 1)) 
    print(solution(2, 4)) 
    print(solution(1000, 1000)) 
    print(solution(1, 1)) 

if __name__ == "__main__":
    main()