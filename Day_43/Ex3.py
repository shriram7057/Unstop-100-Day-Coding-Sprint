def process_test_case(N, Q, A, queries):
    result = []
    
    # Build the segment tree using an iterative approach
    size = N
    tree = [0] * (2 * size)
    
    # Place the initial array in the leaves of the tree
    for i in range(size):
        tree[size + i] = A[i]
    
    # Build the internal nodes of the tree
    for i in range(size - 1, 0, -1):
        tree[i] = max(tree[2 * i], tree[2 * i + 1])
    
    # Process each query
    for query in queries:
        if query[0] == 1:  # Query type "?"
            result.append(tree[1])
        else:
            # Query type "! i X": update the ith position to X (1-indexed)
            x, y = query[1]
            idx = x - 1  # convert to 0-indexed
            pos = idx + size  # corresponding position in the tree
            tree[pos] = y
            # Propagate the change up the tree
            pos //= 2
            while pos:
                tree[pos] = max(tree[2 * pos], tree[2 * pos + 1])
                pos //= 2
    return result

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, Q = map(int, input().split())
        A = list(map(int, input().split()))
        queries = []
        for _ in range(Q):
            query = input().split()
            if query[0] == '?':
                queries.append((1, (0, 0)))
            else:
                x, y = int(query[1]), int(query[2])
                queries.append((0, (x, y)))
        result = process_test_case(N, Q, A, queries)
        for res in result:
            print(res)