import sys 



def solve():
    n, k = map(int, input().split()) 
    s = str(input()) 

    valid = [True] * n 
    for _ in range(k):
        best = -1
        rig = [0] * n
        for i in range(n - 2, -1, -1):
            rig[i] = rig[i + 1]
            if valid[i + 1] and s[i + 1] == ')': 
                rig[i] += 1

        lef = [0] * n 
        for i in range(n): 
            if i > 0: 
                lef[i] = lef[i - 1]
                if valid[i - 1] and s[i - 1] == '(':
                    lef[i] += 1
            if valid[i]:
                mx = (rig[best] if s[best] == '(' else lef[best])
                cmp = (rig[i] if s[i] == '(' else lef[i])
                if best == -1 or mx < cmp:
                    best = i 
        if best > -1:
            valid[best] = False

    ans = str() 
    for i in valid:
        ans += ("0" if i else "1")
    print(ans) 



def main():
    t = int(input())
    for _ in range(t): solve()

main()
