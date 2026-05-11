def max_symmetric_sum(N, arr):
    # Initialize the maximum sum as a very small number
    max_sum = float('-inf')
    
    # Iterate through the first half of the list and calculate sums with the corresponding symmetric element
    for i in range(N // 2):
        current_sum = arr[i] + arr[N - 1 - i]
        max_sum = max(max_sum, current_sum)
    
    # Return the maximum sum found
    return max_sum

# Input parsing
N = int(input())  # Size of Linked List
arr = list(map(int, input().split()))  # The elements of the Linked List

# Get the result
result = max_symmetric_sum(N, arr)

# Print the result
print(result)