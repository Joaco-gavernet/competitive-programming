import sys 

n = int(input()) 
s, f = map(int, input().split()) 

v = []
for i in range(n): 
    b, e = map(int, input().split()) 
    v.append({b, 1})
    v.append({e, -1}) 

sorted(v)
print(v) 

ans = []


print(*ans) 
