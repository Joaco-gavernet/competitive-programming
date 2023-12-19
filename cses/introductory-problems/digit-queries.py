LIMIT = 20

# vector of intervals
intervals = [0]
for i in range(0, LIMIT + 1):
    number = int(str(i) + "8" * i + "9")
    intervals.append(number)


def main(k):
    d = 1
    while d < LIMIT and intervals[d] < k:  # find roof of digits (d)
        d += 1
    n = (
        10**d - 1 - (intervals[d] - k) // d
    )  # find the number containing our digit (n)
    m = (
        intervals[d] - k
    ) % d  # find mod d (rewrite improper fraction as mixed fraction)
    print((n // 10**m) % 10)  # find the digit m (from the right) in n


t = int(input())

while t > 0:
    number = int(input())
    main(number)
    t -= 1
