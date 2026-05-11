from collections import defaultdict

def count_set_bits(x):
    """Returns the number of set bits in the binary representation of x."""
    return bin(x).count('1')

def count_xor_setbit_triplets(N):
    """Finds the number of triplets (A, B, C) satisfying the given conditions."""
    
    # Step 1: Group numbers by their set bit count
    bit_count_groups = defaultdict(list)
    
    for num in range(1, N + 1):
        bit_count_groups[count_set_bits(num)].append(num)
    
    triplet_count = 0
    
    # Step 2: Find valid triplets in each group
    for numbers in bit_count_groups.values():
        num_count = len(numbers)
        
        # Generate all possible (A, B) pairs and check for valid C
        for i in range(num_count):
            for j in range(i + 1, num_count):
                A, B = numbers[i], numbers[j]
                C = A ^ B  # Find potential C
                
                if C in numbers and C > A and C > B:  # Ensure order (avoid duplicates)
                    triplet_count += 1

    return triplet_count

# Read input
N = int(input().strip())

# Compute and print the result
print(count_xor_setbit_triplets(N))