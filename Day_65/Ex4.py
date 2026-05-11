def sum_of_subarray_mins(arr):
    MOD = 10**9 + 7
    N = len(arr)

    # Arrays to store counts of valid subarrays where A[i] is the min
    left = [0] * N
    right = [0] * N

    # Monotonic Stack for "Previous Smaller Element" (PSE)
    stack = []
    for i in range(N):
        while stack and arr[stack[-1]] > arr[i]:
            stack.pop()
        left[i] = i - stack[-1] if stack else i + 1
        stack.append(i)

    # Monotonic Stack for "Next Smaller Element" (NSE)
    stack = []
    for i in range(N - 1, -1, -1):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        right[i] = stack[-1] - i if stack else N - i
        stack.append(i)

    # Compute final sum
    result = sum((arr[i] * left[i] * right[i]) % MOD for i in range(N)) % MOD
    return result

# Read input
N = int(input().strip())
arr = list(map(int, input().strip().split()))

# Output result
print(sum_of_subarray_mins(arr))