def find_best_split_index(n, s):
    if n == 0:
        return 0  # Edge case: Empty string

    prefix_set = set()
    suffix_count = [0] * (n + 1)
    suffix_set = set()

    # Compute distinct digit count for suffix
    for i in range(n - 1, -1, -1):
        suffix_set.add(s[i])
        suffix_count[i] = len(suffix_set)

    max_sum = 0
    best_index = 0

    # Iterate and maintain prefix distinct count
    for i in range(n - 1):  # We stop at n-1 because we need at least one digit in the right part
        prefix_set.add(s[i])
        current_sum = len(prefix_set) + suffix_count[i + 1]

        # Update best split index
        if current_sum > max_sum:
            max_sum = current_sum
            best_index = i

    return best_index

# Input handling
n = int(input())
s = input().strip()

# Output the result
print(find_best_split_index(n, s))