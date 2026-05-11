def process_products(N, IDs, sizes):
    stack = []
    
    for i in range(N):
        # Check if the stack is not empty and if the current element matches the top of the stack
        if stack and stack[-1][0] == IDs[i] and stack[-1][1] == sizes[i]:
            stack.pop()  # Remove the previous element as it forms a pair with the current one
        else:
            stack.append((IDs[i], sizes[i]))  # Push current product onto the stack
    
    # The length of the stack is the size of the remaining array after all removals
    return len(stack)

# Read inputs
import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])  # Size of the vectors
IDs, sizes = [], []

if N > 0:
    IDs = list(map(int, data[1:N+1]))  # Product IDs
    sizes = list(map(int, data[N+1:2*N+1]))  # Product Sizes

# Print the result
print(process_products(N, IDs, sizes))