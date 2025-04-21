
for _ in range(int(input())): 
    n = int(input()) 
    h = [] 
    for _ in range(n):
        h.append(list(map(int,input().split())))
    r = list(map(int,input().split())) 
    c = list(map(int,input().split())) 
    ans = 0 
    for _ in range(2): 
        dp = [0, r[0]] 
        for i in range(1,n):
            ndp = [10**18, 10**18] 
            for x in range(2): 
                for y in range(2):
                    if all([h[i][j] +y != h[i-1][j] +x for j in range(n)]): 
                        ndp[y] = min(ndp[y], dp[x] +y*r[i]) 
            dp = ndp 
        ans += min(dp) 

        # transpose 
        for i in range(n): 
            for j in range(i,n): 
                h[i][j], h[j][i] = h[j][i], h[i][j] 
        r = c 

    if ans >= 10**18:
        ans = -1 
    print(ans) 



