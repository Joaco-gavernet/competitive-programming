

for _ in range(int(input())): 
    a, b, c = map(int, input().split()) 
    sum = (a^b) + (b^c) + (c^a)
    print("correct", sum) 
