from bisect import bisect_right

def maxEventValue(events, k):
    # Sort events based on endDay
    events.sort(key=lambda x: x[1])
    
    # Extract endDays for binary search
    endDays = [event[1] for event in events]
    
    n = len(events)
    
    # DP array: (n+1) x (k+1)
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    
    # Fill DP table
    for i in range(1, n + 1):
        start, end, value = events[i - 1]
        
        # Find last non-overlapping event using binary search
        last_index = bisect_right(endDays, start - 1)
        
        for j in range(1, k + 1):
            # Case 1: Skip current event
            dp[i][j] = dp[i - 1][j]
            
            # Case 2: Attend current event
            if last_index > 0:
                dp[i][j] = max(dp[i][j], value + dp[last_index][j - 1])
            else:
                dp[i][j] = max(dp[i][j], value)
    
    # Maximum value by attending up to k events
    return dp[n][k]

# Input Reading
n = int(input())
events = [list(map(int, input().split())) for _ in range(n)]
k = int(input())

# Output the result
print(maxEventValue(events, k))