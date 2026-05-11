from collections import Counter

def longest_common_subsequence(N, strings):
    # Initialize a counter for the first string
    common_freq = Counter(strings[0])

    # Iterate over all other strings and update the common frequency
    for i in range(1, N):
        # Count the frequency of characters in the current string
        current_freq = Counter(strings[i])

        # Update common_freq by taking the minimum frequency for each character
        for char in list(common_freq.keys()):
            if char in current_freq:
                common_freq[char] = min(common_freq[char], current_freq[char])
            else:
                common_freq[char] = 0
        
        # Remove characters that have 0 frequency in common_freq
        common_freq = {char: count for char, count in common_freq.items() if count > 0}

    # The length of the longest common string is the sum of all frequencies in common_freq
    result = sum(common_freq.values())
    return result

# Input reading
N = int(input())  # number of strings
strings = [input().strip() for _ in range(N)]

# Get the result
result = longest_common_subsequence(N, strings)

# Output the result
print(result)