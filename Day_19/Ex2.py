def num_unique_bsts(n):
    # Catalan number DP array
    catalan = [0] * (n + 1)
    catalan[0] = 1  # Base case

    for i in range(1, n + 1):
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i - 1 - j]

    return catalan[n]

# Input handling
N = int(input())

# Output the number of unique BSTs
print(num_unique_bsts(N))