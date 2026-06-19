import sys 



def solve():
    n = int(input()) 

    a = [x + 1 for x in range(n)] 

    if n % 2 == 0:
        print(*a)
        a.reverse()
        print(*a) 
        a.reverse()
        print(*a) 
        print(*a) 
    else:
        print(*a) 
        a.reverse()
        print(*a) 
        a.reverse() 
        a = a[1:] + a[:1] 
        print(*a) 
        a.reverse() 
        print(*a) 


def main():
    t = int(input())
    for _ in range(t): solve()

main()
