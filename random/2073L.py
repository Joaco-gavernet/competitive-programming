
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def main():
    r, c, n, p = map(int, input().split())
    mat = [[0]] * r
    for i in range(r): 
        mat[i] = list(map(int, input().split()))


    xn, yn = -1, -1
    for i in range(r):
        for j in range(c):
            if mat[i][j] == p:
                yn, xn = i, j
                break

    seen = []
    for s in range(p):
        y, x = yn, xn
        for i in range(4):
            yi = y + dy[i]
            xi = x + dx[i]
            if 0 <= yi and yi < r and 0 <= xi and xi < c:
                if mat[yi][xi] > 0 and mat[yi][xi] + s <= n:
                    seen.append(mat[yi][xi] + s)
                if mat[yi][xi] == mat[y][x] - 1:
                    yn, xn = yi, xi

    seen = list(set(seen))
    print(f"{len(seen)}/{n-1}")


main() 
