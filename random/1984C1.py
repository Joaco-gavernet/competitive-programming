import sys 



def solve():
    n = int(input())
    a = list(map(int, input().split())) 

    dp = [0, 0]
    ndp = [0, 0]
    for x in a:
        ndp[0] = dp[0] + x
        ndp[1] = max(dp[1] + x, abs(dp[0] + x)) 
        dp, ndp = ndp, dp
        # print('dp', dp)
    print(max(abs(dp[0]), dp[1]))

def main():
    t = int(input())
    for _ in range(t): solve()

main()
