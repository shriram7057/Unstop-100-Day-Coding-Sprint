def largest_number_from_two_smallest(arr):
    # Find the two smallest numbers
    first, second = sorted(arr[:2])  # Initialize with first two elements

    for num in arr[2:]:
        if num < first:
            second = first
            first = num
        elif num < second:
            second = num
    
    # Form the largest number using them
    return max(int(str(first) + str(second)), int(str(second) + str(first)))

# Read input
N = int(input().strip())
arr = list(map(int, input().strip().split()))

# Output the largest number
print(largest_number_from_two_smallest(arr))