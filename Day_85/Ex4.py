import sys

def is_prime(n):
    """ Check if a number is prime """
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def max_valid_subsequence_length(s):
    """ Find the longest subsequence where consecutive ASCII differences are 2 """
    dp = {}  # Dictionary to store max sequence length for each character
    max_length = 0
    
    for char in s:
        ascii_val = ord(char)
        # Can be part of a sequence from 'ascii_val - 2' or 'ascii_val + 2'
        dp[ascii_val] = max(dp.get(ascii_val - 2, 0), dp.get(ascii_val + 2, 0)) + 1
        max_length = max(max_length, dp[ascii_val])
    
    return max_length

# Read input
s = sys.stdin.read().strip()

# Get the maximum valid subsequence length
length = max_valid_subsequence_length(s)

# Check if it is a prime number (excluding 1)
print(1 if length > 1 and is_prime(length) else 0)