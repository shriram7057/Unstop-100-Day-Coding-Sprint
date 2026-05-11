def solve():
    # Read input
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    queries = list(map(int, input().split()))

    # Step 1: Compute prefix minimum array
    prefix_min = [0] * n
    prefix_min[0] = arr[0]

    for i in range(1, n):
        prefix_min[i] = min(prefix_min[i - 1], arr[i])

    # Step 2: Answer each query in O(1)
    result = [prefix_min[q] for q in queries]

    # Print output in a single line
    print(" ".join(map(str, result)))

# Run the function
solve()