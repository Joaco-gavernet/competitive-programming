# from math import log2, ceil

# ceil(log2(ns))


def simular(ns, nd, nm):
    laps = 0
    while ns.bit_length() >= nd:
        laps += 1
        ns >>= nd
        ns += nm
        # print("s ", bin(ns))

    # print(laps)
    # print(ceil(log2(ns)))
    ans = laps * nd + ns.bit_length()
    print("{:b}".format(ans))


def main():
    m = str(input())
    d = str(input())
    s = str(input())

    if len(d) > 10:
        print("{:b}".format(len(s)))
    else:
        nd = int(d, 2)
        if len(s) >= nd and len(m) >= nd:
            print("Infinite money!")
        else:
            ns = int(s, 2)
            nm = int(m, 2)
            # print("ns ", ns)
            # print("nm ", nm)
            simular(ns, nd, nm)


main()
