def matchPattern(word, pattern):
    if len(word) != len(pattern):
        return False

    # Use two dictionaries to store character mappings for pattern and word
    pattern_map = {}
    word_map = {}

    for w_char, p_char in zip(word, pattern):
        if pattern_map.get(p_char) != word_map.get(w_char):
            return False
        pattern_map[p_char] = word_map[w_char] = w_char

    return True

def main():
    # Reading input
    N = int(input())
    words = input().split()
    pattern = input()

    # Finding all words that match the pattern
    matched_words = [word for word in words if matchPattern(word, pattern)]

    # Output the result
    print(len(matched_words))
    print(" ".join(matched_words))

# Running the main function
main()