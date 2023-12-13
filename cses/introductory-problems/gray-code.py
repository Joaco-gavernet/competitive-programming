def grayCode(n):
    for i in range(1 << n):
        val = i ^ (i >> 1)

        # val in binary 0bxxxxx format, and slices off the "0b" with [2::]
        s = bin(val)[2::]
        # pads string with 0's to make it n bits long, and appends a newline
        print(s.zfill(n), end="\n")


# reading input and casting to int
n = int(input())
grayCode(n)
