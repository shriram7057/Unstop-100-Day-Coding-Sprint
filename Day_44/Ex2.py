def countWays(N):
    if N == 1:
        return 1
    if N == 2:
        return 2

    a, b = 1, 2  # Base cases: f(1) = 1, f(2) = 2
    for _ in range(3, N + 1):
        a, b = b, a + b  # Fibonacci update

    return b

# Input
N = int(input().strip())
print(countWays(N))