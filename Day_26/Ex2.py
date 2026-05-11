from collections import Counter

def findAnagrams(secret1, secret2):
    len_s1 = len(secret1)
    len_s2 = len(secret2)

    # If Secret 2 is longer than Secret 1, no valid anagrams can exist
    if len_s2 > len_s1:
        print("Empty Array")
        return
    
    # Frequency count of characters in Secret 2
    pattern_count = Counter(secret2)
    # Frequency count of characters in the current window of Secret 1
    window_count = Counter(secret1[:len_s2])
    
    result = []
    
    # If the first window already matches
    if window_count == pattern_count:
        result.append(0)
    
    # Now slide the window over Secret 1
    for i in range(1, len_s1 - len_s2 + 1):
        # Remove the character going out of the window
        window_count[secret1[i - 1]] -= 1
        if window_count[secret1[i - 1]] == 0:
            del window_count[secret1[i - 1]]
        
        # Add the new character coming into the window
        window_count[secret1[i + len_s2 - 1]] += 1
        
        # Check if the current window matches the pattern
        if window_count == pattern_count:
            result.append(i)
    
    # Output the result
    if result:
        print(" ".join(map(str, result)))
    else:
        print("Empty Array")

# Example usage:
secret1 = input().strip()  # Secret 1 input
secret2 = input().strip()  # Secret 2 input
findAnagrams(secret1, secret2)