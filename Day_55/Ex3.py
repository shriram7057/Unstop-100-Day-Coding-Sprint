def subset_sum(N, K, arr):
    dp = [False] * (K + 1)
    dp[0] = True  # Base case: sum 0 is always possible

    for num in arr:
        for j in range(K, num - 1, -1):  # Iterate backwards to avoid overwriting values
            dp[j] |= dp[j - num]  

    return "YES" if dp[K] else "NO"

# Read input
N, K = map(int, input().split())
arr = list(map(int, input().split()))

# Print result
print(subset_sum(N, K, arr))