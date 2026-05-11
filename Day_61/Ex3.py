import sys

# Directions: right, left, down, up
DIRECTIONS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def find_positions(grid, N, M):
    snake, man = None, None
    for r in range(N):
        for c in range(M):
            if grid[r][c] == 's':
                snake = (r, c)
            elif grid[r][c] == 'm':
                man = (r, c)
    return snake, man

def count_paths(grid, x, y, man_x, man_y, visited):
    if (x, y) == (man_x, man_y):
        return 1  # Found a valid path
    
    visited.add((x, y))
    total_paths = 0
    
    for dx, dy in DIRECTIONS:
        nx, ny = x + dx, y + dy
        
        if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]):  # Within bounds
            if (nx, ny) not in visited and grid[nx][ny] != 'w':  # Not visited & not a wall
                total_paths += count_paths(grid, nx, ny, man_x, man_y, visited)
    
    visited.remove((x, y))  # Backtrack
    return total_paths

def snake_paths(N, M, grid):
    # Find start (snake) and end (man) positions
    snake, man = find_positions(grid, N, M)
    
    if not snake or not man:  # If either is missing
        return 0
    
    sx, sy = snake
    mx, my = man
    
    return count_paths(grid, sx, sy, mx, my, set())

# Input handling
N = int(sys.stdin.readline().strip())
M = int(sys.stdin.readline().strip())
grid = [sys.stdin.readline().strip().split() for _ in range(N)]

# Output result
print(snake_paths(N, M, grid))