MOD = 10**9 + 7

def count_valid_strings(N):
    if N == 0:
        return "1"

    # Initial count of single character strings
    a, e, i, o, u = 1, 1, 1, 1, 1  

    for _ in range(N - 1):
        na = (e + u) % MOD
        ne = (i + a) % MOD
        ni = (o + e) % MOD
        no = (u + i) % MOD
        nu = (a + o) % MOD
        a, e, i, o, u = na, ne, ni, no, nu  # Update states

    # Compute total count and convert to octal
    total = (a + e + i + o + u) % MOD
    return oct(total)[2:]  # Convert to octal and remove '0o' prefix

# Read input and print result
N = int(input())
print(count_valid_strings(N))