import sys

def solve(tokens):
    A = next(tokens) 
    B = next(tokens) 
    C = next(tokens) 
    X = next(tokens) 
    Y = next(tokens) 
    D = next(tokens) 

    # case using A
    best = ((D + X - 1) // X) * A

    # case using A and B
    if D > X:
        coc = D // (X + Y)
        tota = coc * A
        totb = coc * Y * B
        times = coc * Y
        rest = D - coc *(X +Y)
        if rest > 0:
            tota += A
            if rest < X:
                tot = coc *(X +Y) +X
                if (tot -D) >= times:
                    times = 0
                    totb = 0
                else:
                    totb -= (tot -D) *B
                    times -= (tot -D) 
            if rest > X:
                totb += (rest -X) * B
                times += rest -X
        if X*B > A:
            cant = times // X
            totb -= cant *B *X
            tota += cant *A
        best = min(best, tota + totb)

    # case using A, finish with B and C
    dist = D -X -Y
    cost = A + B*Y
    if dist > 0:
        # fill with C
        aux = dist *C
        best = min(best, cost + aux) 

        # fill with A
        aux = dist // X *A
        aux += (dist %X) *C
        best = min(best, cost + aux) 

        # fill with A and B
        aux = (dist // (X+Y)) *(A +(Y*B))
        extra = (dist % (X+Y)) *C
        best = min(best, cost + aux + extra)

    print(best)


def main():
    tokens = map(int, sys.stdin.read().split()) 
    t = next(tokens) 
    for i in range(t):
        solve(tokens)

main() 
