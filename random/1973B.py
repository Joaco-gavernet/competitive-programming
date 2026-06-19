import sys 


def solve():
    n = int(input()) 
    a = list(map(int, input().split()))

    B = (max(a)).bit_length() 
    ans = 0 
    for j in range(B):
        act = 0
        ok = False 
        for i in range(n): 
            if a[i] & (1<<j) == 0:
                act += 1
            else:
                ok = True 
                ans = max(ans, act) 
                act = 0
        if ok:
            ans = max(ans, act) 
    print(ans + 1) 


def main():
    t = int(input())
    for _ in range(t): solve()

main()
