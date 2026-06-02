


def solve(): 
    n = int(input())
    p = list(map(int, input().split()))
    d = list(map(int, input().split()))

    ans = [0] * n
    visited = [False] * n

    for i in range(n):
        u = d[i] - 1
        while visited[u] == False:
            visited[u] = True
            u = p[u] - 1
            ans[i] += 1
        if i - 1 >= 0:
            ans[i] += ans[i - 1]

    print(*ans)


def main():
    t = int(input())
    for i in range(t): solve();

main()
