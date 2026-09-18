import sys 
sys.set_int_max_str_digits(100000)


def main(): 
    n = int(input()) 
    if n < 3: 
        print(-1)
    elif n == 3:
        print(210)
    else:
        x = 10 ** (n - 1) 
        r = x % 210 
        x += 210 - r 
        print(x) 


main() 
