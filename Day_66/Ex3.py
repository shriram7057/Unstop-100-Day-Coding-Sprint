from collections import deque

def can_reach_end(matrix, N, T):
    """ Check if we can reach (N-1, N-1) from (0,0) with max level ≤ T using BFS """
    if matrix[0][0] > T:
        return False  # Cannot even start
    
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    queue = deque([(0, 0)])
    visited = set([(0, 0)])
    
    while queue:
        x, y = queue.popleft()
        if (x, y) == (N - 1, N - 1):
            return True
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < N and (nx, ny) not in visited:
                if matrix[nx][ny] <= T:
                    queue.append((nx, ny))
                    visited.add((nx, ny))
    
    return False  # Cannot reach the goal

def min_time_to_clear_game(N, matrix):
    """ Binary search on T to find the minimum time needed to reach (N-1, N-1) """
    left, right = matrix[0][0], max(matrix[i][j] for i in range(N) for j in range(N))
    ans = right
    
    while left <= right:
        mid = (left + right) // 2
        if can_reach_end(matrix, N, mid):
            ans = mid
            right = mid - 1  # Try smaller T
        else:
            left = mid + 1  # Increase T
    
    return ans

# Input handling
N = int(input())
matrix = list(map(int, input().split()))
matrix = [matrix[i * N:(i + 1) * N] for i in range(N)]

# Output result
print(min_time_to_clear_game(N, matrix))