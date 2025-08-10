def main():
    n, t = map(int, input().split())
    mins = float(2000.0)
    d = [0] * n
    s = [0] * n
    for i in range(n):
        d[i], s[i] = map(int, input().split())
        mins = min(float(d[i] / t) - s[i], float(mins))

    IT = 60
    l = mins
    r = 10**6
    while True:
        c = (l + r) / 2
        anst = 0
        for i in range(n):
            anst += d[i] / (c + s[i])
        if abs(t - anst) < 10**-12:
            print(c)
            return
        if anst < t:
            r = c
        else:
            l = c


main()
