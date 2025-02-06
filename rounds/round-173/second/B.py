import sys 
import math 
input = lambda: sys.stdin.readline().rstrip() 

sys.set_int_max_str_digits(6000) 

for _ in range(int(input())): 
    n, d = map(int, input().split()) 

    ans = [1]

    if n >= 3 or d %3 == 0: 
        ans.append(3) 

    if d == 5: 
        ans.append(5) 

    if n >= 3 or d == 7: 
        ans.append(7) 

    if n >= 6 or d == 9 or (n >= 3 and d %3 == 0): 
        ans.append(9) 

    print(*ans) 

