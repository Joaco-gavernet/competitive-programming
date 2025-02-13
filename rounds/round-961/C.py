import math

def solve():
    n = int(input())
    a = list(map(int, input().split())) 
    p = n *[1]

    for i in range(n-1): 
        if a[i +1] == 1:
            if a[i] == 1:
                continue
            else:
                print(-1)
                return

        p[i+1] = math.ceil(p[i] *math.log(a[i], a[i+1]))
        if p[i +1] != 0: 
            aux = math.ceil(math.log2(p[i+1]))
            p[i+1] = 2**aux
        else:
            p[i +1] = 1

    ops = 0
    for i in range(n):
        if p[i] != 0: 
            ops += math.ceil(math.log2(p[i]))

    print(int(ops))



for _ in range(int(input())):
    solve()

