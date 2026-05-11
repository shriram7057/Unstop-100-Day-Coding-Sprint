def calculate_difference(num):
    """
    Write your logic here.
    Parameters:
        num (int): The number chosen by Lexi's friend
    Returns:
        int: The difference between the maximum and minimum possible values
    """
    is_negative = num < 0
    digits = list(str(abs(num)))  # Convert to list of digits as strings
    
    # Sort digits to find minimum and maximum values
    digits_sorted_asc = sorted(digits)
    digits_sorted_desc = sorted(digits, reverse=True)
    
    # Reconstruct minimum and maximum numbers
    min_num = int(''.join(digits_sorted_asc))
    max_num = int(''.join(digits_sorted_desc))
    
    # If the original number was negative, swap min and max
    if is_negative:
        min_num, max_num = -max_num, -min_num
    
    # Calculate the difference
    difference = max_num - min_num
    return difference
    pass


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()

    T = int(data[0])  # The first line contains a single integer T
    results = []
    
    for i in range(1, T + 1):
        num = int(data[i])  # Each of the next T lines contains a single integer
        # Call the user logic function
        result = calculate_difference(num)
        results.append(result)
    
    for result in results:
        print(result)


if __name__ == "__main__":
    main()