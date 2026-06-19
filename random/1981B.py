import sys 



def solve():
    n, m = map(int, input().split()) 

    i = 0
    ans = n
    while i < 35:
        base = n & ((1<<i) - 1)
        if (1<<i) > n:
            if (1<<i) - base <= m:
                ans |= (1<<i)
        else:
            p = base + 1
            q = (1<<i) - base
            if min(p, q) <= m:
                ans |= (1<<i)
        i += 1
    print(ans) 



def main():
    t = int(input())
    for _ in range(t): solve()

main()
