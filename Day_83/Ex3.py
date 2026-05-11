# Read input
A1, A2, N = map(int, input().split())

# Calculate common difference
d = A2 - A1

# Calculate N-th term
A_N = A1 + (N - 1) * d

# Print the roll number
print(A_N)