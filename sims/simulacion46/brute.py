
p = 99867713
for i in range(2 * 10 ** 7): 
    u = floor(log(1e9 / 11) / log(17) - 1e-6)
    r = (u ** (u + 1)) % p
    print(r)
