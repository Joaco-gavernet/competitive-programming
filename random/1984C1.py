import sys 



def solve():
    n = int(input())
    a = list(map(int, input().split())) 

    dp = [0, 0]
    ndp = [0, 0]
    for x in a:
        ndp[0] = dp[0] + x
        ndp[1] = max(abs(dp[0] + x), abs(dp[1] + x)) 
        dp, ndp = ndp, dp
    print(max(dp[0], dp[1]))

def main():
    t = int(input())
    for _ in range(t): solve()

main()
