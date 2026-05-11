MOD = 10**9 + 7

def countWaysToConstructSum(N):
    dp = [0] * (N + 1)
    dp[0] = 1  # Base case: 1 way to make sum 0 (by using nothing)
    
    for i in range(1, N + 1):
        for j in range(1, 7):  # We can use numbers from 1 to 6
            if i - j >= 0:
                dp[i] = (dp[i] + dp[i - j]) % MOD
    
    return dp[N]

# Read input
N = int(input().strip())

# Print the result
print(countWaysToConstructSum(N))