import sys 



def solve():
    n, k = map(int, input().split()) 
    a = list(map(int, input().split()))  
    a.sort() 
    a.reverse() 

    i = 0
    while i < n: 
        par = 0
        act = a[i]
        while i < n and a[i] == act:
            par ^= 1
            i += 1
        if par == 0 or (i < n and 0 <= i - 1 and a[i - 1] <= a[i] + k):
            print("YES")
            return 
    print("NO")


def main():
    t = int(input())
    for _ in range(t): solve()

main()
