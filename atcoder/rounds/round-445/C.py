import math

def main():
    n = int(input())
    v = list(map(int, input().split()))
    for i in range(n):
        v[i] -= 1

    PW = 333
    jmp = [[0 for x in range(n)] for y in range(PW)]
    for i in range(n):
        jmp[0][i] = i
        jmp[1][i] = v[i]

    for step in range(2, PW):
        for i in range(n): 
            jmp[step][i] = jmp[step-1][jmp[step-1][i]]

    ans = []
    for i in range(n):
        x = int(10 ** 100)
        pos = i 
        while x > 0:
            pos = jmp[int(math.log2(x))][pos]
            x //= 2
        ans.append(pos)

    for i in range(n):
        ans[i] += 1
    print(*ans)

main()
