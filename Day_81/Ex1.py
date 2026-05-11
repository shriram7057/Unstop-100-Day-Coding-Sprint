def process_words():
    # Read input
    N = int(input().strip())  # Number of words
    words = input().split()   # List of words
    remove_char = input().strip()  # Character to remove
    
    # Process words to compute lengths after removal
    lengths = [len(word.replace(remove_char, '')) for word in words]
    
    # Sort lengths
    lengths.sort()
    
    # Print the result
    print(*lengths)

# Run the function
process_words()