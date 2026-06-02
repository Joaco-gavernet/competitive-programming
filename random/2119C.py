
def solve():
    n, l, r, k = map(int, input().split())

    if n % 2 == 1:
        print(l)
    else:
        p = int(l.bit_length())
        if (1<<p) <= r and n >= 4:
            if k <= n - 2:
                print(l)
            else:
                print(1<<p)
        else:
            print(-1)


def main():
    t = int(input())
    for i in range(t): solve();

main()
