def excel_column_name(n):
    """ Convert a number to its corresponding Excel column name """
    result = []
    while n > 0:
        n -= 1  # Adjust for 1-based index
        result.append(chr(n % 26 + ord('A')))
        n //= 26
    return ''.join(result[::-1])  # Reverse for correct order

def max_product_excel_name(words):
    n = len(words)
    word_masks = []
    word_lengths = []

    # Step 1: Create bitmasks for each word
    for word in words:
        bitmask = 0
        for char in word:
            bitmask |= (1 << (ord(char) - ord('a')))  # Set corresponding bit
        word_masks.append(bitmask)
        word_lengths.append(len(word))

    # Step 2: Compute max product of lengths of non-overlapping words
    max_product = 0
    for i in range(n):
        for j in range(i + 1, n):
            if word_masks[i] & word_masks[j] == 0:  # No common letters
                max_product = max(max_product, word_lengths[i] * word_lengths[j])

    # Step 3: Convert max product to Excel column name
    return excel_column_name(max_product) if max_product > 0 else "0"

# Input handling
num_words = int(input())
words = input().split()

# Compute and print result
print(max_product_excel_name(words))