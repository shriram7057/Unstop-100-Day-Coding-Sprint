def apply_shifts(n, s, shifts):
    result = []
    
    for i in range(n):
        shift = shifts[i] % 26
        new_char = chr((ord(s[i]) - ord('a') + shift) % 26 + ord('a'))
        result.append(new_char)
    
    return "".join(result)


def main():
    import sys
    data = sys.stdin.read().strip().split()
    
    n = int(data[0])
    s = data[1]
    shifts = list(map(int, data[2:2+n]))
    
    print(apply_shifts(n, s, shifts))


if __name__ == "__main__":
    main()