import sys 
import math 

# input = lambda: sys.stdin.readline().rstrip() 
# sys.set_int_max_str_digits(6000) 

def checks(pref, inicio, fin):
    inicio += 1; fin += 1
    l = inicio -1; r = inicio; ax = 0
    while r < fin: 
        ax = max(ax, pref[r] -pref[l]) 
        if pref[r] -pref[l] <= 0:
            l = r 
        r += 1

    l = inicio -1; r = inicio; an = 0
    while r < fin: 
        an = min(an, pref[r] -pref[l]) 
        if pref[r] -pref[l] >= 0:
            l = r 
        r += 1
    return an, ax


for _ in range(int(input())): 
    n = int(input()) 
    a = list(map(int, input().split()))  

    idx = -1 
    for i in range(n): 
        if abs(a[i]) != 1: 
            idx = i 

    # two-pointers to find best max and min in left interval [0, idx] 
    pref = [0]
    gn = gx = 0
    for x in a:
        pref.append(pref[-1] + x) 

    if idx != -1: 
        an, ax = checks(pref, 0, idx) 
        bn, bx = checks(pref, idx +1, n) 
        gn = min(an, bn); gx = max(ax, bx)  
    else: 
        gn, gx = checks(pref, 0, n) 

    ans = set()  
    for x in range(gn, gx +1):
        ans.add(x) 
        
    # second part considering idx != -1
    if idx != -1: 
        an = ax = 0
        i = idx -1
        x = 0 
        while i >= 0: 
            x += a[i] 
            an = min(an, x) 
            ax = max(ax, x) 
            i -= 1 

        bn = bx = 0
        i = idx +1
        x = 0 
        while i < n: 
            x += a[i] 
            bn = min(bn, x) 
            bx = max(bx, x) 
            i += 1 
        gn = an + bn; gx = ax + bx 
        for x in range(gn, gx +1): 
            ans.add(a[idx] +x) 
    print(len(ans)) 
    print(*sorted(ans)) 
