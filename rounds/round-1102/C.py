import sys 


# Rotate left by k steps
def rotate_left(arr, k):
    k = k % len(arr)
    return arr[k:] + arr[:k]

def solve():
    n = int(input()) 
    h = list(map(int, input().split())) 

    ans = []
    for i in range(n):
        mx = 0
        for j in range(n):
            if h[mx] < h[j]:
                mx = j

        stk = [0] # monotonic increasing stack in [0, mx]  
        for j in range(1, mx): 
            if h[stk[-1]] <= h[j]:
                stk.append(j) 
        stk.append(mx) 
        lef = 0 
        for j in range(1,len(stk)):
            lef += h[stk[j - 1]] * (stk[j] - stk[j - 1]) 

        stk = [n - 1] # monotonic decreasing stack in [mx + 1, n - 1]
        for j in range(n - 2, mx - 1, -1):
            if h[stk[-1]] <= h[j]:
                stk.append(j) 
        stk.reverse() 
        rig = 0
        for j in range(len(stk) - 2, -1, -1):
            rig += h[stk[j + 1]] * (stk[j + 1] - stk[j]) 

        ans.append(lef + rig) 
        h = rotate_left(h, 1) 

    print(*ans) 



def main():
    t = int(input())
    for _ in range(t): solve()

main()
