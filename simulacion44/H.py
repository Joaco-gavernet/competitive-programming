

def main(): 
    c = int(input()) 
    v = list(map(int, input().split())) 
    w = list(map(int, input().split())) 
    n = len(v) 

    dp = [-1]*(c+1)
    dp[0] = 0
    for j in range(n):
        for ci in range(c,0,-1): 
            if ci -w[j] < 0 or dp[ci -w[j]] == -1: 
                continue
            if dp[ci -w[j]] +v[j] > dp[ci]: 
                dp[ci] = dp[ci -w[j]] +v[j]
    print(max(dp)) 


main() 
