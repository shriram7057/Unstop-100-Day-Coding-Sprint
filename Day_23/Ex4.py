import re

def replace_acronyms(S, N, key_value_pairs):
    # Step 1: Create a dictionary for key-value pairs
    acronym_dict = {key: value for key, value in key_value_pairs}
    
    # Step 2: Use regular expressions to find all acronyms in the string
    def replace(match):
        acronym = match.group(1)  # This extracts the acronym within parentheses
        # Step 3: Return the value for the acronym or '?' if not found
        return acronym_dict.get(acronym, "?")
    
    # Step 4: Replace all occurrences of (acronym) in the string using the replace function
    result = re.sub(r'\((.*?)\)', replace, S)
    
    # Output the result
    print(result)


# Input parsing
S = input().strip()  # The input string
N = int(input())  # Number of key-value pairs

key_value_pairs = []
for _ in range(N):
    key, value = input().split()
    key_value_pairs.append((key, value))

replace_acronyms(S, N, key_value_pairs)