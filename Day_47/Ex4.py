def min_moves_to_balance(s):
    open_needed, close_needed = 0, 0
    
    for char in s:
        if char == '(':
            open_needed += 1  # Count extra opening brackets
        elif char == ')':
            if open_needed > 0:
                open_needed -= 1  # Match an opening bracket
            else:
                close_needed += 1  # Count extra closing brackets
                
    return open_needed + close_needed  # Total insertions needed

def count_primes(n):
    if n < 2:
        return 0
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    
    for i in range(2, int(n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False
    
    return sum(sieve)

# Input
s = input().strip()
M = min_moves_to_balance(s)
print(count_primes(M))