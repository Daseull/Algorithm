
MOD = int(1e9)


n = int(input())
dp = [[0] * 10 for _ in range(n+1)] # dp[i][j] = 길이가 i고 끝글자가 j인 계단수의 개수 %MOD
for i in range(1, 10):
    dp[1][i] = 1 #초기값 

for i in range(2, n+1):
    dp[i][0] = dp[i-1][1]
    dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD
    dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD
    dp[i][3] = (dp[i-1][2] + dp[i-1][4]) % MOD
    dp[i][4] = (dp[i-1][3] + dp[i-1][5]) % MOD
    dp[i][5] = (dp[i-1][4] + dp[i-1][6]) % MOD
    dp[i][6] = (dp[i-1][5] + dp[i-1][7]) % MOD
    dp[i][7] = (dp[i-1][6] + dp[i-1][8]) % MOD
    dp[i][8] = (dp[i-1][7] + dp[i-1][9]) % MOD
    dp[i][9] = dp[i-1][8]

answer = 0
for i in range(10):
    answer += dp[n][i]

print(answer % MOD)