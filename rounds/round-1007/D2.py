


def f(a, ax, m):
    if m <= len(a):
        return a[m -1]
    else:
        res = m // 2
        if res <= len(ax):
            return ax[res -1]
        else: 
            if res % 2: 
                return ax[-1]
            else:
                return ax[-1] ^ f(a, ax, res)


for _ in range(int(input())): 
    n, l, r = map(int, input().split()) 
    a = list(map(int, input().split())) 
    m = l

    ax = [] 
    for x in a:
        if len(ax):
            ax.append(ax[-1] ^ x)
        else:
            ax.append(x)

    if len(ax) %2 == 0: 
        a.append(ax[(n // 2) -1]) 
        ax.append(ax[-1] ^ a[-1]) 

    print(f(a, ax, m))
