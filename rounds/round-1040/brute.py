
twos = 0
p = 70
dp = [0]*(p+1)
dp[0] = 0
acc = [0]
for i in range(1, p): 
    dp[i] = dp[i-1] +i -1
    acc.append(acc[-1] +dp[i])
# print("dp =", dp)
s = list(map(int, input().split()))

# s = [0, 0, 2, 1, 0, 2]
# s = [0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 0, 0, 0, 1, 0, 1, 0, 1, 0, 2, 1, 0, 2, 2]

for c in s:
    if c == 2:
        twos += 1

def solve(ops): 
    ops.reverse()

    tot = 0
    stk = []
    for c in s: 
        if c == 2:
            c = ops.pop()
        if c == 0:
            stk.append(c)
        elif c == 1: 
            while len(stk) and stk[-1] > 0:
                tot += dp[stk[-1]]
                tot += stk[-1]
                stk.pop()
            if len(stk) and stk[-1] == 0: 
                stk.pop()
                if len(stk) and stk[-1] > 0: 
                    stk[-1] += 1
                else:
                    stk.append(1)
    while len(stk):
        tot += dp[stk[-1]] + stk[-1]
        stk.pop()
    return tot

def transf(x): 
    input = []
    while x > 0: 
        input.append(x %2)
        x //= 2
    while len(input) < twos:
        input.append(0)
    input.reverse()
    return input

def main(): 
    dict = {}
    for i in range(2 ** twos): 
        aux = transf(i)
        aux2 = aux.copy()
        dict[str(aux2)] = solve(aux)
    print(dict)

main()

