n = int(input())
arr = [int(n) for n in input().split()]  # read array from input

prefixSum = [0] * (n + 1)  # declaration of size
prefixSum[1] = arr[0]  # first element of prefix sum
for i in range(1, (n + 1)):
    prefixSum[i] = prefixSum[i - 1] + arr[i - 1]

l = 0
r = 1
ans = float("-inf")

while r < (n + 1):
    ans = max(prefixSum[r] - prefixSum[l], ans)
    if prefixSum[r] - prefixSum[l] < 0:
        l = r
    r += 1

print(ans)
