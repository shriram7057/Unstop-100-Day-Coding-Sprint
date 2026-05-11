import sys
from collections import Counter

def remove_invalid_chars(s):
    # Step 1: Count frequency of each character
    freq = Counter(s)
    
    # Step 2: Remove characters where freq[char] is divisible by (ord(char) - ord('a') + 1)
    filtered_string = [ch for ch in s if freq[ch] % (ord(ch) - ord('a') + 1) != 0]
    
    # Step 3: Print the resulting string (or empty string if all characters are removed)
    print("".join(filtered_string))

# Read input
s = sys.stdin.readline().strip()

# Process the string
remove_invalid_chars(s)