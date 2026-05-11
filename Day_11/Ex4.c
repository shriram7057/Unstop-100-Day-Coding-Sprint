from collections import deque, defaultdict

def total_non_functional_cost(K, N, M, edges):
    # Handle the case where M = 0
    if M == 0:
        return 0

    # Step 1: Create adjacency list
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    # Step 2: BFS traversal from node 0
    visited = set([0])
    queue = deque([0])
    non_functional_count = 0

    while queue:
        node = queue.popleft()
        # Step 3: Check non-functional condition
        if node != 0 and node % M == 0:
            non_functional_count += 1

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    # Step 4: Calculate total cost
    return non_functional_count * K


# Driver code
if __name__ == "__main__":
    # Input parsing
    K = int(input().strip())
    N = int(input().strip())
    M = int(input().strip())
    length = int(input().strip())
    edges = [list(map(int, input().strip().split())) for _ in range(length)]

    # Output the total cost
    print(total_non_functional_cost(K, N, M, edges))