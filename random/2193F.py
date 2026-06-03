import sys

# Override default input() with the faster system readline
input = lambda: sys.stdin.readline().rstrip("\r\n")


def solve():
    n, ax, ay, bx, by = map(int, input().split())
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))

    evt = [(x[i], y[i]) for i in range(n)]
    evt.append((ax, ay))
    evt.append((bx, by))
    evt.sort()

    ops = [] 
    ref, bot = evt[0]
    top = bot
    for i in range(1,len(evt)):
        u, v = evt[i]
        if u == ref:
            top = v
        else: 
            ops.append((bot, top))
            ref = u
            bot, top = v, v
    ops.append((bot, top))

    dpp = [0, 0]
    dp = [0, 0]
    pbot, ptop = ops[0]
    for i in range(1,len(ops)): 
        bot, top = ops[i]
        dp[0] = min(dpp[0] + abs(bot - pbot) + (top != bot) * 2 * max(0, top - pbot), 
                       dpp[1] + abs(bot - ptop) + (top != bot) * 2 * max(0, top - ptop)) 
        dp[1] = min(dpp[0] + abs(top - pbot) + (top != bot) * 2 * max(0, pbot - bot), 
                       dpp[1] + abs(top - ptop) + (top != bot) * 2 * max(0, ptop - bot)) 
        dpp = dp.copy()
        pbot, ptop = bot, top

    sys.stdout.write(str(bx - ax + min(dp)) + "\n")


def main():
    t = int(input())
    for i in range(t): solve(); 

main()
