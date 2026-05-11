def sum_of_squares(n):
    """ Returns the sum of squares of digits of n """
    total = 0
    while n > 0:
        digit = n % 10
        total += digit * digit
        n //= 10
    return total

def is_good_number(n):
    """
    Determines if a number is a "good" number (eventually reaches 1)
    using Floyd's cycle detection.
    
    Parameters:
        n (int): The number to check
    
    Returns:
        bool: True if the number is good, False otherwise
    """
    slow = n
    fast = sum_of_squares(n)

    while fast != 1 and slow != fast:
        slow = sum_of_squares(slow)
        fast = sum_of_squares(sum_of_squares(fast))  # Move twice as fast

    return "true" if fast == 1  else "false"

def main():
    import sys
    input_data = sys.stdin.read().strip()
    n = int(input_data)
    print(is_good_number(n))

if __name__ == "__main__":
    main()