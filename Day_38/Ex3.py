from collections import Counter

def sort_by_frequency(s):
    # Count frequency of each character
    freq = Counter(s)

    # Sort by (-frequency, lexicographically)
    sorted_chars = sorted(freq.keys(), key=lambda c: (-freq[c], c))

    # Build the result string
    return ''.join(c * freq[c] for c in sorted_chars)

# Input handling
s = input().strip()
print(sort_by_frequency(s))