def execute_instructions(n, pos, instruction):
    m = len(instruction)
    result = [0] * m  # Initialize result array

    # Iterate over each starting index
    for i in range(m):
        row, col = pos  # Start from initial position
        count = 0

        # Try executing instructions from index i
        for j in range(i, m):
            move = instruction[j]
            if move == 'L':
                col -= 1
            elif move == 'R':
                col += 1
            elif move == 'U':
                row -= 1
            elif move == 'D':
                row += 1
            
            # If out of bounds, break
            if row < 0 or row >= n or col < 0 or col >= n:
                break
            
            count += 1
        
        result[i] = count  # Store count for this start index
    
    return result

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # Grid size (n x n)
    pos = [int(data[1]), int(data[2])]  # Start position (row, col)
    m = int(data[3])  # Instruction length
    instruction = data[4]  # Instruction string
    
    # Call user logic function and print the output
    result = execute_instructions(n, pos, instruction)
    
    # Print result as space-separated values
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()