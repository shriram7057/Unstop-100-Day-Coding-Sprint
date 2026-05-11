from collections import deque
import sys

def sliding_window_maximum(N, K, heights):
    q = deque()  # Stores indices of elements in the current window
    result = []

    for i in range(N):
        # Remove elements that are out of the current window
        if q and q[0] < i - K + 1:
            q.popleft()

        # Maintain decreasing order: remove smaller elements from the back
        while q and heights[q[-1]] <= heights[i]:
            q.pop()

        # Add the current element index
        q.append(i)

        # Append result once we have a full window
        if i >= K - 1:
            result.append(heights[q[0]])  # Max element is always at the front

    print(" ".join(map(str, result)))

# Read input
N, K = map(int, sys.stdin.readline().split())
heights = list(map(int, sys.stdin.readline().split()))

# Process and print output
sliding_window_maximum(N, K, heights)