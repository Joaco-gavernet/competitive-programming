
n = int(input()) 
tot = 0
v = list(map(int, input().split()))
ans = 0
for x in v:
    tot += x
    ans = min(ans, tot)

print(abs(ans))
