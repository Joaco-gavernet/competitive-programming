def comprimir(v):
    n = len(v)
    ans = []
    done = False
    if n == 2:
        if v[0] == v[1]:
            v = [2 * v[0]]
            return True, v
        else:
            return False, v
    i = 1
    while i < n:
        if v[i] == v[i - 1]:
            ans.append(2 * v[i])
            j = i +1
            while j < n:
                ans.append(v[j])
                j += 1
            v = ans
            return True, v
        else:
            ans.append(v[i - 1])
        i += 1
    if n > 2 and v[n - 1] != v[n - 2]:
        ans.append(v[n - 1])
    v = ans
    return done, v

def eliminar(v):
    n = len(v)
    ans = []
    if n == 2:
        v = [max(v)]
    else:
        if v[1] <= v[0]:
            ans.append(v[0])
        i = 1
        while i < n - 1:
            if v[i - 1] < v[i] or v[i] > v[i + 1]:
                ans.append(v[i])
            i += 1
        if v[n-2] <= v[n-1]: 
            ans.append(v[n-1])
        v = ans
    return v

def main():
    n = int(input())
    v = list(map(int, input().split()))
    while len(v) > 1:
        done, v = comprimir(v)
        if not done:
            v = eliminar(v)
        # print(v)
    print(v[0])

main()
