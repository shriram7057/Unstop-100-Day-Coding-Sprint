import heapq
from collections import Counter

def count_unique_numbers(N, arr):
    # Frequency map to count occurrences
    freq = Counter(arr)

    # Max-heap (use negative numbers to simulate max-heap)
    max_heap = [-num for num in freq.keys()]
    heapq.heapify(max_heap)

    unique_count = 0

    while max_heap:
        max_val = -heapq.heappop(max_heap)  # Get max value

        if freq[max_val] == 1:  # If it's unique
            unique_count += 1
            new_val = max_val // 2  # Compute half
            if new_val > 0:
                freq[new_val] += 1  # Update frequency
                heapq.heappush(max_heap, -new_val)  # Push new value back
        else:
            # Remove all occurrences of max_val
            del freq[max_val]

    return unique_count

# Read input
N = int(input())
arr = list(map(int, input().split()))

# Print result
print(count_unique_numbers(N, arr))