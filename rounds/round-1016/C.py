

for _ in range(int(input())): 
    x, k = map(int, input().split()) 

    if x == 1 and k == 2: print("YES"); continue; 
    if k > 1:
        print("NO") 
    else:
        prim = True
        d = 2 
        while d*d <= x and prim:
            if x %d == 0:
                prim = False 
            d += 1
        print("YES" if prim else "NO") 
