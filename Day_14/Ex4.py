def largest_power_of_2(N):
    # Find the largest power of 2 less than or equal to N
    return 1 << (N.bit_length() - 1)

# Read input
N = int(input().strip())

# Find and print the result
print(largest_power_of_2(N))