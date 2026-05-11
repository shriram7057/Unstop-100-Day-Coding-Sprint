def count_ones_in_binary(n):
    count = 0
    i = 0
    
    while (1 << i) <= n:
        cycle_len = 1 << (i + 1)
        full_cycles = n // cycle_len
        count += full_cycles * (1 << i)
        
        remainder = n % cycle_len
        count += max(0, remainder - (1 << i) + 1)
        
        i += 1
    
    return count

if __name__ == "__main__":
    n = int(input())
    print(count_ones_in_binary(n))