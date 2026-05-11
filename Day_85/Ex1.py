import sys

def preprocess_prefix_sum(arr):
    """Computes prefix sum array in O(N)"""
    n = len(arr)
    prefix = [0] * n
    prefix[0] = arr[0]
    
    for i in range(1, n):
        prefix[i] = prefix[i - 1] + arr[i]
    
    return prefix

def get_sum(prefix, l, r):
    """Returns sum from index l to r in O(1) using prefix sum"""
    if l > r:
        return 0
    return prefix[r] - (prefix[l - 1] if l > 0 else 0)

def process_queries(n, arr, queries):
    """Processes queries and prints results"""
    prefix = preprocess_prefix_sum(arr)
    results = []
    
    for left, index, right in queries:
        left_sum = get_sum(prefix, left, index - 1)
        right_sum = get_sum(prefix, index + 1, right)
        product = left_sum * right_sum
        results.append(str(max(0, product)))  # If negative, print '0'

    sys.stdout.write("\n".join(results) + "\n")

# Fast input reading
input = sys.stdin.read
data = input().split()

# Read N and Q
n = int(data[0])
q = int(data[1])

# Read array elements
arr = list(map(int, data[2:n+2]))

# Read queries
queries = []
index = n + 2
for _ in range(q):
    queries.append(tuple(map(int, data[index:index+3])))
    index += 3

# Process queries and print results
process_queries(n, arr, queries)