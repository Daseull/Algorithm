
MOD = int(1e6)

code = input()
n = len(code)
dp = [0] * (n+1) # dp[i] = i번째 글자부터 맨 끝까지 해석할 수 있는 방법수
dp[n] = int(code[0] != '0')

for i in reversed(range(n)):
    # 한글자로 해석 
    if code[i] != '0':
        dp[i] = dp[i+1]
    # 두글자로 해석 
    if i+1 < n and 10 <= int(float(code[i:i+2])) <= 26:
        dp[i] += dp[i+2]
    dp[i] %= MOD

print(dp[0])