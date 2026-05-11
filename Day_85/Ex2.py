import sys

def projection_area(grid, N):
    top_view = sum(1 for i in range(N) for j in range(N) if grid[i][j] > 0)
    front_view = sum(max(row) for row in grid)
    side_view = sum(max(grid[i][j] for i in range(N)) for j in range(N))
    
    return top_view + front_view + side_view

# Read input
input_data = sys.stdin.read().split()
N = int(input_data[0])
grid = [list(map(int, input_data[i*N+1:(i+1)*N+1])) for i in range(N)]

# Compute projection area
result = projection_area(grid, N)
print(result)