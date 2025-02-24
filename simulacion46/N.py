import math


def col_round(x):
    frac = x - math.floor(x)
    if frac < 0.5:
        return math.floor(x)
    return math.ceil(x)


def main():
    n = int(input())
    c = list(map(str, input().split()))

    v = [-1] * n
    for i in range(n):
        if c[i] != "?":
            v[i] = int(c[i])

    l = 0
    r = 10**16

    for i in range(n, 0, -1):
        # print(i)
        # print(l, r)
        if v[i - 1] == -1:
            continue
        lb = 0
        rb = i * v[i - 1]
        while rb - lb > 1:
            m = (lb + rb) // 2
            if col_round(m / i) == v[i - 1]:
                rb = m
            else:
                lb = m
        l = max(l, rb)

        lb = i * v[i - 1]
        rb = 10**16
        while rb - lb > 1:
            m = (lb + rb) // 2
            if col_round(m / i) == v[i - 1]:
                lb = m
            else:
                rb = m
        r = min(r, lb)

    print(l)


main()
