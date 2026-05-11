from collections import deque
import sys

def min_time_to_eat_cheese(grid, N):
    # Directions: Up, Right, Down, Left
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    
    queue = deque()
    cheese_count = 0  # Total cheese in the grid

    # Find all starting positions (rat locations) and count total cheese
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 2:
                queue.append((i, j, 0))  # (row, col, time)
            elif grid[i][j] == 1:
                cheese_count += 1

    # If there's no cheese, return 0 (no time needed)
    if cheese_count == 0:
        return 0

    max_time = 0  # Track the last time step
    while queue:
        r, c, time = queue.popleft()
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < N and grid[nr][nc] == 1:
                grid[nr][nc] = 2  # Mark cheese as eaten
                cheese_count -= 1  # Reduce cheese count
                queue.append((nr, nc, time + 1))
                max_time = max(max_time, time + 1)

    # If all cheese was eaten, return the time. Otherwise, return -1.
    return max_time if cheese_count == 0 else -1

# Read input
N = int(sys.stdin.readline().strip())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

# Output result
print(min_time_to_eat_cheese(grid, N))