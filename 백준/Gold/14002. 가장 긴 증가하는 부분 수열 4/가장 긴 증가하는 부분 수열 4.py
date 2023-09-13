
n = int(input())
arr = list(map(int, input().split()))

dp = [[1, n] for i in range(n)] 

max_len = 0
start = 0 
for i in reversed(range(n)):
    for j in range(i+1, n):
        if arr[i] < arr[j] and dp[i][0] <= dp[j][0]:
            dp[i][0] = dp[j][0] + 1
            dp[i][1] = j
    if dp[i][0] > max_len :
        max_len = dp[i][0]
        start = i
        
print(max_len)
while start < n:
    print(arr[start], end=' ')
    start = dp[start][1] 




