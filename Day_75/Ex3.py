from collections import deque

def min_operations_to_expand_identifier(N, K):
    # Convert K to string to check initial digit count
    if len(str(K)) >= N:
        return 0  # Already meets the requirement

    # BFS setup
    queue = deque([(K, 0)])  # (current_value, steps)
    visited = set([K])

    while queue:
        current, steps = queue.popleft()
        str_current = str(current)

        # Try multiplying by each digit in the current number
        for digit in str_current:
            digit = int(digit)
            if digit > 1:  # Multiplication by 0 or 1 is useless
                new_value = current * digit
                if new_value not in visited:
                    if len(str(new_value)) >= N:
                        return steps + 1  # Reached required digits
                    queue.append((new_value, steps + 1))
                    visited.add(new_value)

    return -1  # Impossible to reach N digits

# Read input
N, K = map(int, input().split())
print(min_operations_to_expand_identifier(N, K))