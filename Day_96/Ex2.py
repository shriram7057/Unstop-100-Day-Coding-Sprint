import math

def solve(x, y):
    """
    Parameters:
        x (int): Number of pages Ram needs to write
        y (int): Number of pages Rakesh needs to write
    Returns:
        int: Number of days it will take for at least one of them to complete their assignment
    """
    if x == 0 or y == 0:
        return 0  # If either person has 0 pages to write, they are already done.

    days = 0
    while x > 0 and y > 0:
        gcd_value = math.gcd(x, y)
        x -= gcd_value
        y -= gcd_value
        days += 1
    
    return days


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    x = int(data[0])  # First input is the number of pages Ram needs to write
    y = int(data[1])  # Second input is the number of pages Rakesh needs to write
    
    # Call user logic function and print the output
    result = solve(x, y)
    print(result)


if __name__ == "__main__":
    main()