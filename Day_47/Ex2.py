def count_lucky_strings(N):
    """
    Write your logic here.
    Parameters:
        N (int): Length of the string
    Returns:
        int: Number of lucky strings of length N
    """
    pass


def main():
    import sys
    input = sys.stdin.read
    data = input().strip()
    
    N = int(data)  # The first and only input is the integer N
    
    # Call user logic function and print the output
    result = count_lucky_strings(N)
    print(result)


if __name__ == "__main__":
    main()
