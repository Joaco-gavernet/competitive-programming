import sys 



def solve():
    n = int(input()) 
    a = list(map(int, input().split())) 
    for i in range(n):
        a[i] -= 1
    good = [[False for _ in range(n)] for _ in range(n)] 

    for i in range(n):
        vis = [0] * n
        mn, mx = a[i], a[i]
        for j in range(i, n):
            if (vis[a[j]]):
                break
            vis[a[j]] = 1
            mn = min(mn, a[j]) 
            mx = max(mx, a[j]) 
            if mx - mn == j - i:
                good[mn][mx] = True 

    for ans in range(n, 0, -1):
        for i in range(n + 1 - 2 * ans):
            if good[i][i + ans - 1] and good[i + ans][i + 2 * ans - 1]: 
                print(ans)
                return
    print(0)



def main():
    t = int(input())
    for _ in range(t): solve()

main()
