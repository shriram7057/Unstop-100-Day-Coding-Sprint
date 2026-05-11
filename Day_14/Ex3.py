def find_museum_positions(lakes):
    # Extract the x and y coordinates
    x_coords = [lake[0] for lake in lakes]
    y_coords = [lake[1] for lake in lakes]
    
    # Sort the coordinates
    x_coords.sort()
    y_coords.sort()
    
    # Find the median position ranges
    N = len(lakes)
    
    # For the x-coordinates:
    if N % 2 == 1:
        x_median_count = 1
    else:
        x_median_count = x_coords[N // 2] - x_coords[N // 2 - 1] + 1
    
    # For the y-coordinates:
    if N % 2 == 1:
        y_median_count = 1
    else:
        y_median_count = y_coords[N // 2] - y_coords[N // 2 - 1] + 1
    
    # The number of positions for the museum is the product of the possibilities in both dimensions
    return x_median_count * y_median_count

# Input Reading
N = int(input())  # Read number of lakes
lakes = [tuple(map(int, input().split())) for _ in range(N)]

# Solve and print the result
result = find_museum_positions(lakes)
print(result)