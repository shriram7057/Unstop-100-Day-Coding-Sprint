def user_logic(n, arr):
    x = arr[0]
    for i in range(1, n):
        x &= arr[i]
    return x


def main():
    import sys
    data = sys.stdin.read().strip().split()
    
    n = int(data[0])
    arr = list(map(int, data[1:]))
    
    print(user_logic(n, arr))


if __name__ == "__main__":
    main()