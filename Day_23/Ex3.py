from collections import Counter

def find_anagram_substrings(S, P):
    N = len(S)
    M = len(P)
    
    if N < M:
        print("none")
        return
    
    # Frequency of characters in P
    p_freq = Counter(P)
    
    # Frequency of characters in the current window in S
    window_freq = Counter(S[:M])
    
    # List to store the starting indices (1-based)
    result = []
    
    # Check the first window
    if window_freq == p_freq:
        result.append(1)
    
    # Slide the window across S
    for i in range(1, N - M + 1):
        # Remove the character that is going out of the window
        window_freq[S[i - 1]] -= 1
        if window_freq[S[i - 1]] == 0:
            del window_freq[S[i - 1]]
        
        # Add the character that is coming into the window
        window_freq[S[i + M - 1]] += 1
        
        # Check if the current window matches the frequency of P
        if window_freq == p_freq:
            result.append(i + 1)  # 1-based index
    
    # Output the result
    if result:
        print(len(result))
        print(" ".join(map(str, result)))
    else:
        print("none")

# Input reading
S = input().strip()  # The string of blocks
P = input().strip()  # The baby alien's name

# Call the function to find anagrams
find_anagram_substrings(S, P)