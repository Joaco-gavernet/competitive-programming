n, k = map(int, input().split()) 
r = list(map(int, input().split())) 

ans = 0
for x in r:
    ans += ans
    ans += x

ans += n 
print(ans)
