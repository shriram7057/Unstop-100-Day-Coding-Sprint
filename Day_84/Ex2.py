def count_empty_subarrays(arr):
    prefix = 0
    freq = {0: 1}  # handles subarrays starting at index 0
    count = 0

    for x in arr:
        prefix += x
        if prefix in freq:
            count += freq[prefix]
            freq[prefix] += 1
        else:
            freq[prefix] = 1

    return count


def main():
    import sys
    data = sys.stdin.read().strip().split()
    
    n = int(data[0])
    arr = list(map(int, data[1:]))
    
    print(count_empty_subarrays(arr))


if __name__ == "__main__":
    main()