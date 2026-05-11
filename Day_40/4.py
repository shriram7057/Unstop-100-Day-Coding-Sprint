def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        a = []
        b = []
        for _ in range(n):
            ai, bi = map(int, input().split())
            a.append(ai)
            b.append(bi)

        nan = 0
        uppu = n + 1

        while nan < uppu - 1:
            k = (nan + uppu) // 2
            c = 0
            for i in range(n):
                if c < k and a[i] >= k - c - 1 and b[i] >= c:
                    c += 1

            if c >= k:
                nan = k
            else:
                uppu = k

        print(nan)

if __name__ == "__main__":
    main()