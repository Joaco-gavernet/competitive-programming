import sys
from math import isqrt

SVAL = [str(i) for i in range(64)]
NEG = '-1'
INF = 63   # enough because max useful answer <= log2(3e5) < 20


def main():
    it = iter(map(int, sys.stdin.buffer.read().split()))
    t = next(it)
    out = []

    for _ in range(t):
        n = next(it)
        dp = [INF] * (n + 1)

        for _ in range(n):
            dp[next(it)] = 1

        # dp[x] == 1 means x exists in the original array.
        # Only original values can be used as one multiplier.
        lim = isqrt(n)
        d = dp

        for x in range(2, lim + 1):
            if d[x] == 1:
                xx = x * x
                for y in range(xx, n + 1, x):
                    v = d[y // x] + 1
                    if v < d[y]:
                        d[y] = v

        out.append(' '.join(NEG if v == INF else SVAL[v] for v in d[1:]))

    sys.stdout.write('\n'.join(out))


if __name__ == '__main__':
    main()
