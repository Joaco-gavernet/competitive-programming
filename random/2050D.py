import sys 



def solve():
    si = str(input()) 
    s = [ord(c) for c in si] 

    for i in range(len(s)):
        while i > 0 and s[i] - 1 > s[i - 1]:
            s[i] -= 1
            s[i], s[i - 1] = s[i - 1], s[i]
            i -= 1
    print("".join(chr(c) for c in s))


def main():
    t = int(input())
    for _ in range(t): solve()

main()
