def comp(s):
    us = set(s)
    ans = "".join(us)
    return ans

def main(): 
    s = str(input()) 
    t = str(input()) 

    rem = 0
    conts = {} 
    contt = {} 
    for c in t: 
        conts[c] = 0
        if c in contt: 
            contt[c] += 1
        else:
            contt[c] = 1
    for c in s:
        if c == '?':
            rem += 1
        else:
            if c in conts: 
                conts[c] += 1
            else:
                conts[c] = 1

    l = 0
    r = 10 ** 8 + 1
    tc = comp(t)
    while l + 1 < r:
        mid = (l + r) // 2
        aux = rem
        for c in tc:
            aux -= max(0, (contt[c] * mid) - conts[c])
        if aux < 0: 
            r = mid
        else: 
            l = mid

    i = 0
    ans = list(s)
    for c in tc:
        need = max(0, (contt[c] * l) - conts[c])
        while need > 0: 
            if ans[i] == '?': 
                ans[i] = c
                need -= 1
            i += 1

    for i in range(len(ans)):
        if ans[i] == '?':
            ans[i] = 'x'

    print(''.join(ans)) 

main()
