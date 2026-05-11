def smallest_prime_factor(n):
    if n % 2 == 0:
        return 2
    i = 3
    while i * i <= n:
        if n % i == 0:
            return i
        i += 2
    return n  # n is prime

def user_logic(n):
    # If n is prime
    spf = smallest_prime_factor(n)
    if spf == n:
        return 1
    
    # Otherwise
    return 1 + (n - spf) // 2

n = int(input())
result = user_logic(n)
print(result)