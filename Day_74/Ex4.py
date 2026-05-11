from collections import Counter
from math import factorial

def count_permutations(s):
    freq = Counter(s)
    max_char, max_freq = max(freq.items(), key=lambda x: x[1])

    total_permutations = factorial(len(s))
    for char in freq:
        total_permutations //= factorial(freq[char])

    reduced_length = len(s) - (max_freq - 1)
    freq[max_char] = 1  

    grouped_permutations = factorial(reduced_length)
    for char in freq:
        grouped_permutations //= factorial(freq[char])

    return total_permutations - grouped_permutations

T = int(input())
for _ in range(T):
    s = input().strip()
    print(count_permutations(s))