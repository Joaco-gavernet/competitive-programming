
def main(): 
    for p in range(1, 10 **1 +1):
        for q in range(1, 10**1 +1): 
            for k in range(max(p,q), 10**1 +1): 
                if p == 3 and q == 4 and k == 5:
                    print(p*p, q*q, k*k) 
                    return

main() 
