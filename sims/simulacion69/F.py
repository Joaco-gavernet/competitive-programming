import sys


def main():
    s, c = map(str, sys.stdin.read().split())
    ci = int(c)
    n = len(s)

    a = int(0)
    b = int(s)
    for i in range(1, n):
        a = a * 10 + (b // (10 ** (n - i)))
        b = b % (10 ** (n - i))
        if a == (b * ci):
            print(a, b)
            return


main()
