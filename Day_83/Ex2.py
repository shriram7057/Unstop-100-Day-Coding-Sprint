def is_magical(s):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}  # Closing → Opening mapping
    
    for char in s:
        if char in mapping:  # If it’s a closing bracket
            top_element = stack.pop() if stack else '#'  # Pop from stack or set invalid
            if mapping[char] != top_element:  # Check for mismatch
                return False
        else:
            stack.append(char)  # Push opening brackets
    
    return not stack  # If stack is empty, it's valid

# Read input
s = input().strip()
print(is_magical(s))