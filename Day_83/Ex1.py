def decode_message(S):
    i = 0
    result = []
    
    while i < len(S):
        # If we find a '#' at position i+2, it means we have a two-digit encoded character
        if i + 2 < len(S) and S[i + 2] == '#':
            num = int(S[i:i+2])  # Extract the number before '#'
            result.append(chr(96 + num))  # Convert to character
            i += 3  # Move past the processed part
        else:
            num = int(S[i])  # Single-digit case
            result.append(chr(96 + num))
            i += 1  # Move to the next character
    
    return ''.join(result)

# Read input
S = input().strip()
print(decode_message(S))