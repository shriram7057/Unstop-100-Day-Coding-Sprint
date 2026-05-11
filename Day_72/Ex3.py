def minFallingPathSum(grid):
    n = len(grid)
    
    # Previous row DP array
    prev = grid[0][:]  
    
    for i in range(1, n):
        # Finding two minimums from the previous row
        min1, min2 = float('inf'), float('inf')
        for val in prev:
            if val < min1:
                min2 = min1
                min1 = val
            elif val < min2:
                min2 = val
        
        # Current row DP array
        curr = [0] * n
        for j in range(n):
            if prev[j] == min1:
                curr[j] = grid[i][j] + min2
            else:
                curr[j] = grid[i][j] + min1
        
        # Move to next row
        prev = curr
    
    return min(prev)

# Input handling
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Output result
print(minFallingPathSum(grid))