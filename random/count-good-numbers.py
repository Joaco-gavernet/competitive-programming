
def count(x):
    tot = x//2
    tot += x//3 -x//6
    tot += x//5 -x//10 -x//15 +x//30
    tot += x//7 -x//14 -x//21 -x//35
    tot += x//42 +x//105 +x//70 -x//210
    return tot


def solve():
    l, r = map(int, input().split())
    print((r-count(r)) -(l-1-count(l-1)))



t = int(input())
for i in range(t):
    solve()
