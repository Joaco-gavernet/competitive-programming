import sys 



def solve():
    n, x, y, z = map(int, input().split()) 
    nn = n

    # using AI 
    a = 0
    if n <= z * x:
        a = (n + x - 1) // x 
    else:
        n -= z * x
        a = z + (n + (x + y * 10) - 1) // (x + y * 10) 

    # not using AI 
    n = nn 
    b = (n + (x + y) - 1) // (x + y) 

    print(min(a, b)) 



def main():
    t = int(input())
    for _ in range(t): solve()

main()
