import sys 


MOD = 998244353
N = 10 ** 5 + 5 

s = [0] * N
s[0] = 1
for i in range(1,N):
    s[i] = s[i - 1] * 2 % MOD


def solve():
    n = int(input()) 
    p = list(map(int, input().split())) 
    q = list(map(int, input().split())) 

    r = [] 
    i, j, k = 0, 0, 0 
    while k < n:
        if p[k] > p[i]: i = k;
        if q[k] > q[j]: j = k;
        if p[i] != q[j]:
            if p[i] > q[j]:
                r.append((s[p[i]] + s[q[k - i]]) % MOD) 
            else:
                r.append((s[q[j]] + s[p[k - j]]) % MOD) 
        else:
            r.append((s[p[i]] + s[max(q[k - i], p[k - j])]) % MOD) 

        k += 1

    print(*r) 



def main():
    t = int(input())
    for _ in range(t): solve()

main()
