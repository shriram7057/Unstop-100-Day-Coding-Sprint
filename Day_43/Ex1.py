def user_logic(n):
    MODULO = 10**9 + 7

    if n == 0:
        return 2
    if n == 1:
        return 1

    prev2, prev1 = 2, 1  # Base cases L(0) = 2, L(1) = 1

    for _ in range(2, n + 1):
        current = (prev1 + prev2) % MODULO
        prev2, prev1 = prev1, current  # Move window forward

    return prev1

def main():
    import sys
    input = sys.stdin.read
    n = int(input().strip())
    print(user_logic(n))

if __name__ == "__main__":
    main()