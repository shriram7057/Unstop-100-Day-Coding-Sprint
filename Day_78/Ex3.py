from collections import defaultdict
from math import gcd

def maxPointsOnLine(points):
    n = len(points)
    if n < 2:
        return n
    
    max_points = 1  # At least one point exists
    
    for i in range(n):
        slopes = defaultdict(int)  # Store slope counts
        local_max = 0
        
        for j in range(n):
            if i == j:
                continue
            
            x1, y1 = points[i]
            x2, y2 = points[j]
            
            dx = x2 - x1
            dy = y2 - y1
            
            # Reduce fraction by GCD to avoid precision issues
            g = gcd(dx, dy)
            slope = (dx // g, dy // g)
            
            slopes[slope] += 1
            local_max = max(local_max, slopes[slope])
        
        # +1 to include the base point itself
        max_points = max(max_points, local_max + 1)
    
    return max_points

# Read input
n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

# Compute and print result
print(maxPointsOnLine(points))