import sys 

n = int(input()) 
a, b = map(int, input().split()) 
c, d = map(int, input().split()) 

tot = c*n +d -(a*n +b) + c -a 
print(tot) 
