
for _ in range(int(input())): 
    n, l, r = map(int, input().split()) 
    a = list(map(int, input().split())) 
    m = l

    print("#test", _ +1)

    while len(a) <= m:
        x = 0
        for i in range((len(a) +1) // 2):
            x ^= a[i] 
        a.append(x) 

    ax = [] 
    for x in a:
        if len(ax):
            ax.append(ax[-1] ^ x)
        else:
            ax.append(x)

    print(ax) 
    print(ax[m -1]) 
    print("=================================") 


