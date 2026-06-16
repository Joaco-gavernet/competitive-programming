import sys 



def solve():
    n, k = map(int, input().split())
    s = str(input()) 

    for i in range(min(k, n)):
        j = i 
        xor = int(0)
        while j < n:
            xor ^= int(s[j])
            j += k 
        if xor == 1:
            print("NO")
            return 
    print("YES") 




def main():
    t = int(input())
    for _ in range(t): solve()

main()
