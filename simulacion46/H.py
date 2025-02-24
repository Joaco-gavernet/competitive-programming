def main():
    n, a1, k, p = map(int, input().split())

    ans = []

    z = 0
    while z < n:
        # print(a1, z)
        u = 0
        while a1 * (k**u) < p and z + u < n:
            u += 1

        for i in range(5):
            ans.append(int(a1 * (k ** (u - 1 - i))))
        # print(u, a1 * k ** (u - 1), a1 * k**u)
        a1 = (a1 * k**u) % p
        z += u

    ans = sorted(ans)
    print(ans)
    print(*ans[-5:])


main()
