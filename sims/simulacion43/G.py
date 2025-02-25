from math import comb

n, k = map(int, input().split())
p = list(map(float, input().split()))

if n == 1:
    print(100)
elif k == 1:
    a = []
    for i in range(n):
        a.append(100 / n)
    print(*a)
else:
    toprint = []
    for i in range(n):
        acum = p[i]
        ans = 0
        j = 2
        while n - j >= k - 2:
            r = (n + i - j + 1) % n
            ans += acum * comb(n - j, k - 2)
            acum += p[r]
            j += 1
        toprint.append(ans / comb(n, k))
    print(*toprint)
