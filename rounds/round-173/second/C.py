import sys 
import math 

# input = lambda: sys.stdin.readline().rstrip() 
# sys.set_int_max_str_digits(6000) 

def checks(pref, inicio, fin):
    inicio += 1; fin += 1
    print("inicio y fin", inicio, fin) 
    l = ax = inicio -1; r = inicio
    while r < fin: 
        ax = max(ax, pref[r] -pref[l]) 
        if pref[r] -pref[l] <= 0:
            l = r 
        r += 1

    l = inicio -1; r = inicio; an = 0
    while r < fin: 
        print("in", l, r) 
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
        if a[i] != 1: 
            idx = i 

    # two-pointers to find best max and min in left interval [0, idx] 
    pref = [0]
    gn = gx = 0
    for x in a:
        pref.append(pref[-1] + x) 
    print(pref) 

    print("idx", idx) 
    if idx != -1: 
        an, ax = checks(pref, 0, idx) 
        bn, bx = checks(pref, idx +1, n) 
        print("deb", bn, bx) 
        gn = min(an, bn); gx = max(ax, bx)  
    else: 
        gn, gx = checks(pref, 0, n) 

    ans = [] 
    for x in range(gn, gx +1):
        ans.append(x) 
    print("ans", ans) 

    print("====================================") 


    # two-pointers to find best max and min in right interval [idx, n] 
    # if idx != -1: 

