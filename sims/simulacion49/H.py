def main():
    m = int(input())
    x = 0
    y = 10**8

    while y - x > 1:
        med = (x + y) // 2
        if med * (med + 1) * (2 * med + 1) // 6 < m:
            x = med
        else:
            y = med

    if y * (y + 1) * (2 * y + 1) // 6 == m:
        print("3", y)
    else:
        for i in range(3, 54):
            s = 0
            j = 1
            while s < m:
                s += j**i
                j += 1
            if s == m:
                print(i + 1, j - 1)
                return

        print("impossible")


main()
