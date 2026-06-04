


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    tot = 0
    for i in range(n - 1, m - 1, -1):
        tot += min(a[i], b[i])

    # consider where we'll fall inside [0, m-1]
    act = 0
    best = 2 ** 60
    for i in range(m - 1, -1, -1):
        if i < m - 1:
            b[i] += b[i + 1]
            a[i] += b[i + 1]
        best = min(best, a[i]) 
    print(tot + best)

def main():
    t = int(input())
    for i in range(t): solve();

main()
