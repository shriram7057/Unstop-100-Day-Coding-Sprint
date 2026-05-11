def power_mod(n, exp, mod):
    """Computes (n^exp) % mod using fast modular exponentiation."""
    result = 1
    base = n % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def is_power_of_two(x):
    """Checks if x is a power of two."""
    return x > 0 and (x & (x - 1)) == 0

def solve(N):
    MOD = 10007
    mod_inverse = power_mod(N, MOD - 2, MOD)  # Compute modular inverse
    print(1 if is_power_of_two(mod_inverse) else 0)

# Read input
N = int(input().strip())

# Solve the problem
solve(N)