import sys
input = lambda: sys.stdin.readline().rstrip()

for i in range(int(input())): 
    n = int(input()) 
    deg = [0]*n 
    adj = [[] for i in range(n)] 
    for i in range(n-1): 
        u, v = map(int, input().split())
        u -= 1; v -= 1
        deg[u] += 1
        deg[v] += 1
        adj[u].append(v)
        adj[v].append(u) 

    ans = 1
    mans = 0
    # print(deg) 
    sdeg = sorted(deg) 
    # print(sdeg) 

    for i in range(n): 
        ans = deg[i]
        ideg = []
        for v in adj[i]: 
            ideg.append(deg[v]) 
        ideg.append(deg[i]) 
        ideg.sort(reverse = True) 
        # print(ideg) 
        rem = [] 
        mx = -1
        for d in ideg: 
            if sdeg[-1] == d: 
                sdeg.pop()
                rem.append(d)
        rem.reverse() 
        if sdeg:
            mx = sdeg[-1]
        for v in adj[i]:
            mx = max(mx, deg[v] -1)
        for d in rem:
            sdeg.append(d) 
        mans = max(ans +mx -1, mans) 

    print(mans) 
