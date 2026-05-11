import sys
from collections import Counter

def find_first_unique_index(S):
    # Count frequency of each character
    freq = Counter(S)
    
    # Find the first unique character
    for index, char in enumerate(S):
        if freq[char] == 1:
            return index  # Return 0-based index
    
    return -1  # No unique character found

# Read input
S = sys.stdin.read().strip()

# Compute and print the result
print(find_first_unique_index(S))