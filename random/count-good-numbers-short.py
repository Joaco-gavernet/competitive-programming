def good(x):
    return bool(x%2 and x%3 and x%5 and x%7)

def get_naive(x): 
    ans = 0
    for i in range(x): ans += int(good(i))
    return ans

def count(x): 
    return (x // 210) *get_naive(210) + get_naive(x % 210)

for i in range(int(input())):
    l, r = map(int, input().split())
    print(count(r+1) -count(l)) 
