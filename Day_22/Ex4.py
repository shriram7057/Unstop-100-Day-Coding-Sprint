def generate_combinations(n, b, c, a):
    def backtrack(current, count_b, count_c, count_a):
        # If the sequence is of length N, print it
        if len(current) == n:
            results.append("".join(current))
            return
        
        # Add a bell if available
        if count_b > 0:
            backtrack(current + ['B'], count_b - 1, count_c, count_a)
        
        # Add a candy if available
        if count_c > 0:
            backtrack(current + ['C'], count_b, count_c - 1, count_a)
        
        # Add a balloon if available
        if count_a > 0:
            backtrack(current + ['A'], count_b, count_c, count_a - 1)
    
    results = []
    backtrack([], b, c, a)
    return results

# Input handling
inputs = input().split()  # Split the input into space-separated values
n = int(inputs[0])  # First value is the number of accessories required
b, c, a = map(int, inputs[1:])  # Remaining values are the quantities of bells, candies, and balloons

# Generate and print results
combinations = generate_combinations(n, b, c, a)
for combination in combinations:
    print(combination)