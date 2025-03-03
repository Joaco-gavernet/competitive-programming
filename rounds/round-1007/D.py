
def f():


for _ in range(int(input())): 
    n, l, r = map(int, input().split()) 
    a = list(map(int, input().split())) 
    m = l

    print("#test", _ +1)

    ax = [] 
    for x in a:
        if len(ax):
            ax.append(ax[-1] ^ x)
        else:
            ax.append(x)

    if n %2 == 0:
        ax.append(ax[((n +1) //2) -1])
        n += 1
    print(ax) 

    ans = -1
    while m > n:
        print("m", m) 
        if (m // 2) %2 == 1 or (m // 2) <= n:
            ans = ax[min(n, m // 2) -1]
            break
        m //= 2

    print("m", m) 
    print("ans", ans) 
    if ans == -1: 
        if m > n:
            m //= 2
        print(ax[m -1])
    else:
        print(ans)


    print("=================================") 




