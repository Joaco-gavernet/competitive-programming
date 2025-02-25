
def main():
    for i in range(int(input())): 
        n = int(input()) 

        sum = True 
        res = 0
        while n > 0: 
            act = n%1000
            n //= 1000

            if sum: 
                res += act
            else: 
                res -= act
            sum = not sum

        if abs(res) %13 == 0: 
            print(abs(res), "YES") 
        else: 
            print(abs(res), "NO") 

main() 
