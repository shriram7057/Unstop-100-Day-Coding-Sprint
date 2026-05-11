def processString(N, s):
    stack = []
    
    for char in s:
        if char == '_':
            if stack:
                stack.pop()  # Remove the closest letter to the left of the dash
        else:
            stack.append(char)  # Add the letter to the stack
    
    # If the stack is empty, return "-1"
    if not stack:
        return "-1"
    
    # Join the stack to form the resultant string
    return ''.join(stack)

# Input reading
N = int(input())  # Length of the string (though we don't really use it directly)
s = input().strip()  # The string itself

# Processing the string
result = processString(N, s)

# Output the result
print(result)