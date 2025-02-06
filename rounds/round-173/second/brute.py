import sys 
import math 
input = lambda: sys.stdin.readline().rstrip() 


n = 0
while math.floor(math.pow(10, math.factorial(n)) /9) %7 != 0:
    n += 1

print(n) 

