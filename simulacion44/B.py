from math import gcd 

for _ in range(int(input())): 
    sa, sb = map(int, input().split()) 
    a = str(input()) 
    b = str(input()) 

    num = int(a) *int('9' *len(b)) +int(b)
    den = int('9' *len(b)) *10 **len(a)

    while gcd(num, den) != 1:
        d = gcd(num, den)
        num //= d 
        den //= d
    print(num, den) 

