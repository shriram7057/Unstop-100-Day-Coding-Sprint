def lexicographically_smallest_string(n, k):
    # Step 1: Start with all 'a'
    result = ['a'] * n
    remaining = k - n  # Because all 'a' contributes n
    
    # Step 2: Fill from the rightmost position
    for i in range(n-1, -1, -1):
        if remaining == 0:
            break  # Stop if we have reached the required sum
        
        # Maximum we can add to this position (to keep lexicographically smallest)
        add_value = min(25, remaining)  # Max increase is to 'z' (25 extra)
        
        result[i] = chr(ord('a') + add_value)  # Change character
        remaining -= add_value  # Reduce remaining sum
    
    return "".join(result)

# Input
n, k = map(int, input().split())
print(lexicographically_smallest_string(n, k))