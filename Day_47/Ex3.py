from itertools import permutations

def count_unique_words(stickers):
    unique_words = set()

    # Generate all possible words of length 1 to len(stickers)
    for length in range(1, len(stickers) + 1):
        for perm in permutations(stickers, length):
            unique_words.add("".join(perm))
    
    return len(unique_words)

# Input
stickers = input().strip()
# Output
print(count_unique_words(stickers))