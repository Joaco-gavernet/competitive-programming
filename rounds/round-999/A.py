import sys


for _ in range(int(input())):  
    n = int(input()) 
    a = list(map(int, input().split()))

    imp = 0
    for x in a: 
        if x %2 == 1: 
            imp += 1

    par = n -imp
    if par > 0:
        imp += 1
    else: 
        imp -= 1

    print(imp)
