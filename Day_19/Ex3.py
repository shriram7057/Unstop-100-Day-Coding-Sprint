from math import gcd
from collections import Counter

# Function to count valid pairs
def count_pairs(arr, k):
    gcd_count = Counter()
    result = 0

    for num in arr:
        g = gcd(num, k)
        # Count pairs where previous gcds can form a product divisible by k
        for prev_gcd in gcd_count:
            if (g * prev_gcd) % k == 0:
                result += gcd_count[prev_gcd]
        gcd_count[g] += 1  # Update count for current gcd

    return result

# Input handling
k = int(input())
n = int(input())
arr = list(map(int, input().split()))

# Output the result
print(count_pairs(arr, k))