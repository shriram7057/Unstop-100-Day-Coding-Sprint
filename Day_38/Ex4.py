def count_unique_substrings(s):
    unique_substrings = set()
    
    # Generate all substrings of length 2
    for i in range(len(s) - 1):
        unique_substrings.add(s[i:i+2])  # Extract substring of length 2

    return len(unique_substrings)

# Read number of test cases
t = int(input().strip())

# Process each test case
for _ in range(t):
    s = input().strip()
    print(count_unique_substrings(s))