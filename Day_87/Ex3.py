import sys

def is_good_number(num):
    """Check if all digits of num are odd."""
    while num > 0:
        if (num % 10) % 2 == 0:  # Check if last digit is even
            return False
        num //= 10  # Remove last digit
    return True

def find_next_good_number(x):
    """Find the next number greater than x that is a good number."""
    x += 1  # Start checking from the next number
    while not is_good_number(x):
        x += 1
    return x

# Read input
T = int(sys.stdin.readline().strip())  # Number of test cases
results = []

for _ in range(T):
    x = int(sys.stdin.readline().strip())
    results.append(str(find_next_good_number(x)))

# Print all results efficiently
sys.stdout.write("\n".join(results) + "\n")