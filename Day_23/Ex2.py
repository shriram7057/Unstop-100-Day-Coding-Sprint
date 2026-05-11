from collections import Counter

def remove_last_occurrence(N, values):
    # Edge case: if the list is empty
    if N == 0:
        print("")
        return
    
    # Step 1: Calculate frequency of each element
    frequency = Counter(values)
    
    # Step 2: Prepare to construct the new linked list
    result = []
    
    # Step 3: Iterate over the list and append to result excluding last occurrences
    for val in values:
        # If the frequency of current value is more than 1, we add it to the result
        if frequency[val] > 1:
            result.append(val)
            frequency[val] -= 1
        # If the frequency is 1, we skip the element since it's the last occurrence
        elif frequency[val] == 1:
            frequency[val] -= 1
    
    # Step 4: Print the final list
    print(" ".join(map(str, result)))


# Input Parsing
N = int(input())  # Read size of the list
if N > 0:
    values = list(map(int, input().split()))  # Read the elements in the list
else:
    values = []

remove_last_occurrence(N, values)