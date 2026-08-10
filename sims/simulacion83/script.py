
def f(x):
    if x <= 0:
        return 0
    return x * x + f(x - 2)

def solve(): 
    tot = 0
    v = list(map(str, input().split()))
    s = str(v[2])
    if s != "impossible":
        for x in v[2:]:
            num = int(x[:-1]) 
            if x[-1] == 'L': 
                tot += f(num) 
            else: 
                tot += num * (num + 1) * (2 * num + 1) // 6 
        print(v[1], tot)
        assert(tot == int(v[1][:-1])) 

def main():
    t = int(input())
    for i in range(t):
        solve()

main() 
