import heapq as h


# this function finds first_zero_index() counting from right side
def fzi(n):
    # ~n inverts the bits, making the first zero a 1.
    # (n + 1) flips all trailing 1s to 0 and the first 0 to 1.
    # Bitwise AND isolates that specific bit.
    rightmost_zero_mask = ~n & (n + 1)
    
    # .bit_length() returns the 1-based position of the highest bit.
    # Subtracting 1 gives the exact 0-based index from the right.
    return rightmost_zero_mask.bit_length() - 1

def solve():
    n, k = map(int, input().split()) 
    a = list(map(int, input().split())) 

    pq = []
    tot = 0
    evens = 0
    for x in a:
        tot += x.bit_count()
        h.heappush(pq, (fzi(x), x))

    while pq:
        shft, x = h.heappop(pq)
        if (1<<shft) > k:
            break
        else: 
            k -= (1<<shft)
            tot += 1
            x |= (1<<shft)
            h.heappush(pq, (fzi(x), x))

    print(tot)



def main():
    t = int(input())
    for i in range(t): solve();

main()
