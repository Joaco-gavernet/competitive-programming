

def solve(): 
    n = int(input())
    a = list(map(int, input().split())) 
    b = list(map(int, input().split())) 

    op = []
    for i in range(n):
        if b[i] < a[i]:
            op.append((3, i + 1))
            a[i], b[i] = b[i], a[i]

    A = a.copy()
    B = b.copy()
    A.sort()
    B.sort()

    for i in range(n):
        z = -1
        for j in range(i, n):
            if A[i] == a[j]:
                z = j
                break
        while i < z:
            a[z], a[z - 1] = a[z - 1], a[z]
            op.append((1, z))
            z -= 1
    for i in range(n):
        z = -1
        for j in range(i, n):
            if B[i] == b[j]:
                z = j
                break
        while i < z:
            b[z], b[z - 1] = b[z - 1], b[z]
            op.append((2, z))
            z -= 1

    print(len(op))
    for [typ, i] in op:
        print(f"{typ} {i}")

def main():
    t = int(input())
    for _ in range(t): solve();

main()
