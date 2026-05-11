def count_brave_soldiers(n):
    if n < 2:
        return 0

    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    return sum(is_prime)


def main():
    import sys
    n = int(sys.stdin.read().strip())
    print(count_brave_soldiers(n))


if __name__ == "__main__":
    main()