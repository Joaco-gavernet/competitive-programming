import sys 


def apply_floor(x: int, k: int) -> int:
    while k > 0 and x > 0:
        x //= 2
        k -= 1
    return x

def apply_ceil(x: int, k: int) -> int:
    while k > 0 and x > 1:
        x = (x + 1) // 2
        k -= 1
    return x

def solve():
    x, n, m = map(int, input().split()) 
    mn = apply_floor(apply_ceil(x, m), n)
    mx = apply_ceil(apply_floor(x, n), m)
    print(mn, mx)



def main():
    t = int(input())
    for _ in range(t): solve()

main()
