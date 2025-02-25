
def main(): 
    tot = 0
    cant = 0
    for i in range(500):
        print(cant, tot)
        tot += cant
        cant += 1
        if 10 **5 < tot:
            return


main()
