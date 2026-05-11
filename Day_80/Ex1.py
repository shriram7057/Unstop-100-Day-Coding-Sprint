def can_reach_zero(N, X, P):
    S_F = 0
    for F in range(1, min(P, N*2) + 1):  # Limit F to at most 2N for efficiency
        S_F += F
        if (X + S_F) % N == 0:
            return "Yes"
    return "No"

# Read input
T = int(input())  # Number of test cases
for _ in range(T):
    N, X, P = map(int, input().split())
    print(can_reach_zero(N, X, P))