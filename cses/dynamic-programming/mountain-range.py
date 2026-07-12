import sys 

sys.setrecursionlimit(200005)

def build_cartesian_tree(arr):
    n = len(arr)
    parent = [-1] * n
    left_child = [-1] * n
    right_child = [-1] * n

    # Monotonic stack stores indices of elements on the rightmost path
    stack = []

    for i in range(n):
        last_popped = -1

        # Pop elements greater than the current element to maintain min-heap
        while stack and arr[stack[-1]] < arr[i]:
            last_popped = stack.pop()

        # The last popped element becomes the left child of the current element
        if last_popped != -1:
            left_child[i] = last_popped
            parent[last_popped] = i

        # The element left on top of the stack becomes the parent of the current element
        if stack:
            right_child[stack[-1]] = i
            parent[i] = stack[-1]

        stack.append(i)

    # The bottom-most element in the stack is the root of the tree
    root = stack[0] if stack else -1
    return root, parent, left_child, right_child


def solve():
    n = int(input()) 
    h = list(map(int, input().split())) 
    root, parent, left, right = build_cartesian_tree(h)

    # print('h:', h) 
    # print('root:', root) 
    # print('parent:', parent) 
    # print('left:', left) 
    # print('right:', right) 

    memo = {} 
    def up(x): 
        if x in memo:
            return memo[x] 
        px = parent[x] 
        if px == -1: 
            return 1
        else:
            memo[x] = up(px) 
            if h[px] != h[x]:
                memo[x] += 1
            return memo[x]

    best = 0
    for i in range(n):
        best = max(best, up(i)) 


    print(best) 


def main():
    t = 1
    for _ in range(t): solve()

main()
