def will_return_to_origin(n, moves):
    # Initialize coordinates
    x, y = 0, 0

    # Process each move
    for move in moves:
        if move == 'U':
            y += 1
        elif move == 'D':
            y -= 1
        elif move == 'R':
            x += 1
        elif move == 'L':
            x -= 1

    # Check if back to origin
    if x == 0 and y == 0:
        return "YES"
    else:
        return "NO"

# Input Reading
n = int(input())
moves = input().strip()

# Output the result
print(will_return_to_origin(n, moves))