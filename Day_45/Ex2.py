import heapq

def remaining_marbles(n, marbles):
    if n == 1:
        return marbles[0]  # Only one person exists

    # Convert to a max heap (use negative values since Python has a min heap)
    marbles = [-m for m in marbles]
    heapq.heapify(marbles)

    while len(marbles) > 1:
        # Extract top two largest elements
        max1 = -heapq.heappop(marbles)
        max2 = -heapq.heappop(marbles)

        mean_value = (max1 + max2) / 2

        # If mean is a whole number, assign it to the person with max marbles
        if mean_value.is_integer():
            heapq.heappush(marbles, -int(mean_value))

    return -marbles[0] if marbles else 0  # Return remaining marble count

# Input handling
n = int(input().strip())
marbles = list(map(int, input().split()))
print(remaining_marbles(n, marbles))