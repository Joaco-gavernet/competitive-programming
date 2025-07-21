import sys

def solve(tokens): 
    # data = sys.stdin.read()               # read all input at once
    # tokens = data.strip().split()         # split by whitespace
    # A, B, C, X, Y, D = map(int, tokens)   # unpack and convert to int

    A = next(tokens)
    B = next(tokens)
    C = next(tokens) 
    X = next(tokens) 
    Y = next(tokens) 
    D = next(tokens) 

    # TO-DO: contemplar que no puedo sacar mas resto que B's

    # case using A 
    best = (D + X -1) // X * A

    # case using A, finish with B and C 
    aux = D // X * A
    rest = D % X
    if rest > 0: 
        if rest > Y:
            aux += Y * B 
            rest -= Y
            aux += rest * C 
        else: 
            aux += rest * B 
        best = min(best, aux) 

    # case using A and B, finish with A and B
    spend = D // (X + Y) 
    base = spend * (A + Y*B) 
    rest = D - spend * (X + Y)
    if rest > 0: 
        aux = A
        if rest > X: 
            aux += (rest - X) * B
        best = min(best, base + aux)

    # case using A and B, finish with C
    if spend > 0: 
        aux = rest * C
        best = min(best, base + aux) 

    # case using A, B and C, finish with C
    aux = A 
    if D > X: 
        if D > X + Y: 
            aux += Y * B
            aux += (D -X -Y) * C
        else:
            aux += (D -X) * B
    best = min(best, aux)

    # case using A, finish with B's
    coc = D // X
    aux = coc * A
    rest = D % X
    if (rest + Y - 1) // Y <= coc:
        aux += rest * B
    else:
        aux += Y * coc * B
        rest -= Y * coc
        aux += rest * C
    best = min(best, aux)

    print(best) 


def main(): 
    tokens = map(int, sys.stdin.read().split())
    t = next(tokens)
    for i in range(t): 
        solve(tokens) 

main() 
