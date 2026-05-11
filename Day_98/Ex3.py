def countSquares(arr):
    n, m = len(arr), len(arr[0])
    dp = [[0] * m for _ in range(n)]
    total = 0

    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                if i == 0 or j == 0:
                    dp[i][j] = 1  # First row or column stays the same
                else:
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
                total += dp[i][j]  # Sum all squares

    return total

# Read input
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

print(countSquares(arr))