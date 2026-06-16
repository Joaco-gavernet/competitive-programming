import sys 



def solve():
    n = int(input()) 
    h = list(map(int, input().split())) 
    mx = max(h) 
    best = 1
    for i in range(n):
        best = max(best, mx - h[i] + 1) 
    print(best) 


def main():
    t = int(input())
    for _ in range(t): solve()

main()
