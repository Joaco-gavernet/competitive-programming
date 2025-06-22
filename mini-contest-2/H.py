n, m, k = map(int, input().split()) 

s = 'L' if k %2 else 'R'
k -= 1
r = k // (m * 2) + 1
d = (k % (m * 2)) // 2 + 1
print(r, d, s) 
