import sys 
import math 
input = lambda: sys.stdin.readline().rstrip() 

for _ in range(int(input())): 
    n = int(input()) 

    xp = 0
    while n > 3: 
        xp += 1
        n //= 4

    print(1<<xp) 
