import sys
from collections import Counter

def find_special_character(n, s):
    # Step 1: Count frequency of each character
    freq = Counter(s)
    
    # Step 2: Find the first character with frequency 1
    for ch in s:
        if freq[ch] == 1:
            print(ch)
            return
    
    # Step 3: If no such character exists, return -1
    print(-1)

# Read input
n = int(sys.stdin.readline().strip())  # Read n (not used directly)
s = sys.stdin.readline().strip()  # Read string

# Process and find the special character
find_special_character(n, s)