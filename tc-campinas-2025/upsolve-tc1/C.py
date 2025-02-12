import math
from typing import List
from sys import stdin, stdout

g: list[list[int]] = [[] for _ in range(105)]
llegan = [0] *105
dp = [0] *105

def calc(g, llegan, dp, val, n):
    print(llegan) 

def main(): 
    input = stdin.read
    data = input().split()
    idx = 0

    n = int(data[idx])
    idx += 1
    g = [[] for _ in range(n +1)]

    for i in range(n):
        x = int(data[idx])
        idx += 1
        for j in range(x): 
            aux = int(data[idx])
            idx += 1
            g[i +1].append(aux)

    dp = [0] * (n +1)
    llegan = [0] * (n +1)

    dp[0] = 1
    for i in range(1, n +1): 
        if len(g[i]) == 0: 
            dp[i] = dp[i -1]
            continue

        # calc(g, llegan, dp, dp[i -1], n)
        val = dp[i -1]
        llegan = [0] *105
        hijos = 0
        print(i) 
        for nod in range(1, n+1): 
            if nod == 1: 
                llegan[nod] += val
            hijos = len(g[nod]) 
            if hijos > 0: 
                mod_hijos = llegan[nod] % hijos
                print(nod, "[nod hijos] = ", mod_hijos) 
                for i in range(mod_hijos): 
                    llegan[g[nod][i]] += 1
                for i in range(hijos): 
                    llegan[g[nod][i]] += (llegan[nod] // hijos) 
        '''
        '''
        lg = len(g[i])
        if lg == 0:
            lg = 1
        dp[i] = dp[i -1] * (lg // math.gcd(lg, llegan[i])) 
    print(dp) 
    print(dp[n]) 

if __name__ == "__main__":
    main() 


