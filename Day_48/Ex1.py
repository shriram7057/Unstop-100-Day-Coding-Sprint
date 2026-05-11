def max_subsequence(s):
    n = len(s)
    dp = [1] * n

    for i in range(1, n):
        for j in range(i - 1, -1, -1):
            if abs(ord(s[i]) - ord(s[j])) != 1 and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1

    max_length = max(dp)
    return max_length

if __name__ == "__main__":
    s = input().strip()
    print(max_subsequence(s))