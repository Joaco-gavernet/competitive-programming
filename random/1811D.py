import sys 


L = 45
fib = [1] * L

def attempt(x, y, W, H):
    if W == 1 and H == 1:
        return True

    ans = False
    if W < H:
        if y <= H - W:
            ans = attempt(x, y, W, H - W)
        elif W < y:
            ans = attempt(x, y - W, W, H - W)
        else: 
            ans = False
    else:
        if x <= W - H:
            ans = attempt(x, y, W - H, H)
        elif H < x:
            ans = attempt(x - H, y, W - H, H) 
        else:
            ans = False

    return ans


def solve():
    n, x, y = map(int, input().split()) 

    # we'll try to crop some part of the rectangle out at each step 
    a = attempt(x, y, fib[n], fib[n] + fib[n - 1])
    print("YES" if a else "NO")


def main():
    t = int(input())
    for i in range(2,L):
        fib[i] = fib[i - 1] + fib[i - 2]
    for _ in range(t): solve()

main()
