import sys 



def solve():
    n, k = map(int, input().split()) 
    if k % 2 == 1:
        print("NO")
    else:
        l, r = 0, n - 1
        p = [0] * n
        for i in range(n):
            p[i] = i + 1
        while k > 0 and l < r:
            while 2 * (r - l) > k:
                r -= 1
            k -= 2 * (r - l) 
            p[l], p[r] = p[r], p[l] 
            l += 1
            r -= 1

        if k > 0:
            print("NO")
        else: 
            print("YES")
            print(*p) 




def main():
    t = int(input())
    for _ in range(t): solve()

main()

