def count_passwords(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2

    prev1, prev2 = 2, 1  # dp[2] = 2, dp[1] = 1
    for i in range(3, n + 1):
        curr = prev1 + prev2
        prev2 = prev1
        prev1 = curr
    
    return prev1

def main():
    import sys
    input = sys.stdin.read
    n = int(input().strip())
    
    # Call user logic function and print the output
    result = count_passwords(n)
    print(result)

if __name__ == "__main__":
    main()