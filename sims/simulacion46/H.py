from math import log, floor


def main():
    n, r, k, p = map(int, input().split())

    z = 0
    ans = []
    if k == 1:
        for i in range(5):
            ans.append(r)
        print(*ans)
        return 

    if r >= p:
        z += 1
        ans.append(r)
        r *= k
        r %= p

    while z < n:
        u = int(log(p // r) // log(k))
        if r * (k ** u) == p:
            u -= 1
        u = min(u, n -z -1)

        act = []
        for i in range(5):
            pot = u -i 
            if pot < 0: 
                break
            act.append(r * (k ** pot))

        act = sorted(act)
        # print("act", act) 
        for x in act: 
            ans.append(x)
            if len(ans) == n:
                break

        r = (r * k ** (u + 1)) % p
        z += u + 1
        if r == 0:
            while len(ans) < 5:
                ans.append(0)
            break

    # print(ans) 
    assert len(ans) >= 5, "check length"
    ans = sorted(ans)
    print(*ans[-5:])


main()
