def total_extra_value(N, P, arr):
    # Initial sum of array
    initial_sum = sum(arr)
    
    # Track changes over days
    for _ in range(P):
        new_arr = arr[:]
        for i in range(N):
            if arr[i] > 0:
                if i > 0:
                    new_arr[i - 1] += 2
                if i < N - 1:
                    new_arr[i + 1] += 2
        arr = new_arr
    
    # Final sum after P days
    final_sum = sum(arr)
    
    return final_sum - initial_sum

# Read input
N, P = map(int, input().split())
arr = list(map(int, input().split()))

# Print output
print(total_extra_value(N, P, arr))