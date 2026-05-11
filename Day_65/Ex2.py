MOD = 1000000007

def is_248_number(num):
    """Check if a number satisfies the 248 condition."""
    num_str = str(num)
    count_2 = num_str.count('2')
    count_4 = num_str.count('4')
    count_8 = num_str.count('8')
    
    return count_2 > 0 and count_2 == count_4 == count_8

def count_248_numbers(N):
    """Count numbers satisfying the 248 condition up to N."""
    count = 0
    for num in range(1, N + 1):
        if is_248_number(num):
            count = (count + 1) % MOD
    return count

# Input Handling
if __name__ == "__main__":
    import sys
    N = int(sys.stdin.readline().strip())
    print(count_248_numbers(N))