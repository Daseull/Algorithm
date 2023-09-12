t = int(input())
dp = [0] * (11) # dp[i] = i를 만드는 방법 수 
dp = [0, 1, 2, 4, 0, 0, 0, 0, 0, 0, 0]
for _ in range(t):
    n = int(input())
    if dp[n] != 0 :
        print(dp[n])
    else : 
        for i in range(4, n+1):
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1]
        print(dp[n])

