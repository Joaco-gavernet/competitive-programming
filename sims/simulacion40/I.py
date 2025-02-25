import sys 

n, d = map(int, input().split()) 
v = [] *n 

for i in range(d): 
    f, s = map(int, input().split()) 
    v[f -1] += 1
    v[s -1] += 1


