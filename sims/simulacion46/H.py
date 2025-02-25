from math import log, floor


def main():
    n, r, k, p = map(int, input().split())

    ans = [r]

    z = 0
    while z < n:
        print(log(p / r) / log(k) - 1e-6)
        u = floor(log(p / r) / log(k) - 1e-6)

        print(u, r, r * k**u)
        for i in range(1, min(u, n - z)):
            ans.append(r * (k ** (u - i)))

        r = (r * k ** (u + 1)) % p
        z += u

    ans = sorted(ans)
    # print(ans)
    print(*ans[-5:])


main()
