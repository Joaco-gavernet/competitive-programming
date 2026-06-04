import sys 



def solve():
    n = int(input())
    a = list(map(int, input().split()))
    hist = [0] * n 

    for x in a:
        hist[x] += 1

    ans = n
    one = False
    for i in range(n):
        if hist[i] == 1:
            if one:
                ans = i
                break
            else:
                one = True
        elif hist[i] == 0:
            ans = i
            break
    print(ans)



def main():
    t = int(input())
    for _ in range(t): solve()

main()
