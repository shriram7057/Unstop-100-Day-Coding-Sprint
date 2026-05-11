def longest_palindromic_subsequence(s):
    n = len(s)
    dp = [[0] * n for _ in range(n)]

    # Base case: Single character palindromes
    for i in range(n):
        dp[i][i] = 1

    # Fill the DP table
    for length in range(2, n + 1):  # length of substring
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                dp[i][j] = 2 + dp[i+1][j-1] if i + 1 <= j - 1 else 2
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])

    return dp[0][n-1]

# Example test cases
s = input().strip()
print(longest_palindromic_subsequence(s))