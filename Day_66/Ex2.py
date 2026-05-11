import heapq

def minCostPath(grid):
    # Directions (right, left, down, up)
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    n = len(grid)  # Number of rows
    m = len(grid[0])  # Number of columns
    
    # Cost to reach each cell (start with infinity)
    cost = [[float('inf')] * m for _ in range(n)]
    cost[0][0] = 0  # Starting point, no cost
    
    # Min-heap priority queue: stores (cost, x, y)
    pq = [(0, 0, 0)]  # Start at (0, 0) with cost 0
    
    while pq:
        curr_cost, x, y = heapq.heappop(pq)
        
        # If we reach the bottom-right corner, return the cost
        if x == n - 1 and y == m - 1:
            return curr_cost
        
        # Try all four possible directions
        for i, (dx, dy) in enumerate(directions):
            nx, ny = x + dx, y + dy
            
            # Check if the new position is within bounds
            if 0 <= nx < n and 0 <= ny < m:
                # Determine if we need to change the direction
                if grid[x][y] == i + 1:
                    new_cost = curr_cost  # No change needed
                else:
                    new_cost = curr_cost + 1  # We need to change the direction
                
                # If we found a cheaper way to reach (nx, ny), update and push to the queue
                if new_cost < cost[nx][ny]:
                    cost[nx][ny] = new_cost
                    heapq.heappush(pq, (new_cost, nx, ny))
    
    return cost[n - 1][m - 1]

# Input Parsing
N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]

# Output the result
print(minCostPath(grid))