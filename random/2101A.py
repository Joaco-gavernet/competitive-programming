def magical_spiral(n):
    arr = [[-1] * n for _ in range(n)]
    
    if n % 2 == 0:
        x, y = n // 2 - 1, n // 2 - 1
    else:
        x, y = n // 2, n // 2
    
    arr[x][y] = 0
    value = step = 1

    dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]


    while value < n * n:
        for d in range(4):
            steps = step
            
            step += d % 2; dx, dy = dir[d]

            for _ in range(steps):
                x += dx; y += dy

                if 0 <= x < n and 0 <= y < n and arr[x][y] == -1:
                    arr[x][y] = value
                    value += 1
                if value >= n * n:
                    break
            
            if value >= n * n:
                break


    for row in arr:
        print(" ".join(str(num) for num in row))
    print()


t = int(input())

for _ in range(t):
    n = int(input())

    magical_spiral(n)
