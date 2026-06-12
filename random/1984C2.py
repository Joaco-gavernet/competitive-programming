import sys 


N = 5 * 10 ** 5 + 5
MOD = 998244353
p2 = [1] * N 
for i in range(1,N):
    p2[i] = p2[i - 1] * 2 % MOD 

def solve():
    n = int(input())
    a = list(map(int, input().split())) 
    pre = [0] * n
    pre[0] = a[0] 
    for i in range(n-1): pre[i + 1] += pre[i] + a[i + 1]; 

    tot = 0
    mn = min(pre) 
    if mn >= 0:
        tot = p2[n]
    else:
        x = 0
        for i in range(n):
            if pre[i] == mn: tot = (tot + p2[n - i - 1 + x]) % MOD; 
            x += (pre[i] >= 0) 
    print(tot) 


def main():
    t = int(input())
    for _ in range(t): solve()

main()
