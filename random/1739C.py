import sys 


def fact(n): 
    return 1 if n == 0 else n * fact(n - 1) 

def c(n, k): 
    return fact(n) // fact(n - k) // fact(k)

def calc(n): 
    if n == 2: 
        return [1, 0, 1] 
    else: 
        a = calc(n - 2)
        return [c(n - 1, n // 2) + a[1], c(n - 2, n // 2) + a[0], 1]

def solve():
    n = int(input()) 
    M = int(998244353) 
    a = calc(n)
    a = list([x % M for x in a]) 
    print(*a) 

def main():
    t = int(input())
    for _ in range(t): solve()

main()
