n, k = map(int, input().split())

v = list(map(int, input().split()))
v.sort()

INF = float('inf')
dp = [[INF] * (n+1) for _ in range(2)] 

dp[0][0] = dp[1][0] = 0
for i in range(0,n): 
    act = min(dp[0][i], dp[1][i])
    dp[1][i+1] = act +v[i] # kill by hand

    jmp = int((n-i) /2)
    dp[0][i +jmp] = min(dp[0][i +jmp], act +k) # kill with nuke bomb

print(dp[1][n]) 
