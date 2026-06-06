import sys 


MOD = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split())) 

    dp = [0, 0]
    cdp = [1, 1]
    ndp = [0, 0]
    ncdp = [0, 0] 
    for x in a:
        ndp[0] = dp[0] + x
        ncdp[0] = cdp[0] 
        if dp[1] + x == ndp[0]:
            ncdp[0] += cdp[1]
            ncdp[0] %= MOD
        if dp[1] + x == abs(dp[0] + x):
            ndp[1] = dp[1] + x
            ncdp[1] = (cdp[1] + cdp[0]) % MOD
        elif dp[1] + x > abs(dp[0] + x): 
            ndp[1] = dp[1] + x
            ncdp[1] = cdp[1]
        else:
            ndp[1] = abs(dp[0] + x) 
            ncdp[1] = cdp[0]
        dp, ndp = ndp, dp
        cdp, ncdp = ncdp, cdp 

        # print('dp', dp)
    print(cdp[0] if abs(dp[0]) > dp[1] else cdp[1])

def main():
    t = int(input())
    for _ in range(t): solve()

main()
