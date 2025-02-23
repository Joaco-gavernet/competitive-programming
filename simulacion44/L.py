n = int(input())

if n < 9:
    print(n)
elif n <= 16:
    a = [4, 4, 3, 4, 3, 3, 4]
    print(a[n - 10])
else:
    print(((n - 7) // 10) % (10**9 + 7))
