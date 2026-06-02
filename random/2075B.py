


def solve(): 
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    best = 0

    b = list((a[i], i) for i in range(n))
    b.sort()
    b.reverse()
    state = [0] * n
    for i in range(k):
        best += b[i][0]
        state[b[i][1]] = 1

    if k == 1:
        cand = 0
        if a[0] > a[-1]:
            cand = a[0]
            cand += max(a[1:n]) 
        else:
            cand = a[-1]
            if n - 2 > 0:
                cand += max(a[0:n-1]) 
            else: 
                cand += a[0]
        best = cand 
    elif k >= 2:
        imx = -1
        for i in range(n):
            if state[i] == 0 and (imx == -1 or a[imx] <= a[i]):
                imx = i 
        best += a[imx]

    print(best) 


def main():
    t = int(input())
    for i in range(t): solve();

main()
