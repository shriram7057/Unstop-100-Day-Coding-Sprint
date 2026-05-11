def find_final_sum(nums):
    num_set = set(nums)  # Store unique numbers in a set for O(1) lookup
    smallest_missing = 1

    # Find the smallest missing positive integer
    while smallest_missing in num_set:
        smallest_missing += 1

    # ASCII value of the missing integer
    ascii_value = ord(str(smallest_missing))

    # Compute the final sum
    return ascii_value + sum(nums)

# Input Handling
N = int(input())  # Read the size of the array
nums = list(map(int, input().split()))  # Read the array elements

# Compute and print the final result
print(find_final_sum(nums))