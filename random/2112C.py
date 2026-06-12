import sys 



def solve():
    n = int(input()) 
    a = list(map(int, input().split())) 
    a.sort()
    a.reverse() 

    tot = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            l, r = j, n
            while (l + 1 < r): 
                mid = (l + r) // 2
                if (a[i] < a[j] + a[mid] and a[0] < a[i] + a[j] + a[mid]): l = mid; 
                else: r = mid; 
            tot += l - j 
    print(tot) 



def main():
    t = int(input())
    for _ in range(t): solve()

main()
