def query(index,num):
    print("?",index,num)
    return int(input())

def main():
    n = int(input())
    rest = set()
    likely = set()
    for i in range(1,n):
        rest.add(i)
    for i in range(1,n+1):
        likely.add(i)
    D = len(bin(n)[2:])
    ans = 0
    for d in range(D):
        index_0 = set()
        index_1 = set() 
        likely_0 = set()
        likely_1 = set()
        for index in rest:
            res = query(index, 1<<d)   
            if res == 0:
                index_0.add(index)
            else:
                index_1.add(index)  
        zeros = 0
        ones = 0  
        for num in likely:
            if num & (1<<d):
                ones += 1
                likely_1.add(num)
            else:
                zeros += 1
                likely_0.add(num)
        if zeros == len(index_0):
            ans += 1 << d
            rest = index_1
            likely = likely_1
        elif ones == len(index_1):
            rest = index_0
            likely = likely_0
        else:
            print("Error")
            return 
    print("!",ans)

T = int(input())
t = 1
while t <= T:
    main()
    t += 1
