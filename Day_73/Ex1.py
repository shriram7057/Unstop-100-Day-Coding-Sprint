def does_sequence_terminate(N):
    visited = set()
    
    while N != 1:
        if N in visited:
            return "NO"  # Loop detected, sequence is infinite
        visited.add(N)

        if N % 2 == 0:
            N //= 2
        else:
            N = 3 * N + 3
    
    return "YES"  # Sequence terminates

# Input Handling
N = int(input())
print(does_sequence_terminate(N))