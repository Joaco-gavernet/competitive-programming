import math

t = int(input())

for _ in range(t): 
    n = int(input())
    v = list(map(int, input().split()))
    # print(n)
    # print(v)

    vv = []
    for i in range(1,n): 
        vv.append(v[i] -v[i-1])

    vv.sort()
    if n <= 2: 
        print(1)
    else:
        print(vv[-2])
