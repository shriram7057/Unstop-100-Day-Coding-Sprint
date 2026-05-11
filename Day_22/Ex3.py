MOD = 10**9 + 7

def count_valid_pins(n):
    even_positions = (n + 1) // 2  # Count of even-indexed positions
    odd_positions = n // 2         # Count of odd-indexed positions
    
    valid_pins = (pow(5, even_positions, MOD) * pow(4, odd_positions, MOD)) % MOD
    print(valid_pins)

# Read input
n = int(input().strip())
count_valid_pins(n)