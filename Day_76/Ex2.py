def is_good_number(num):
    """Check if a number is 'good' based on the given condition."""
    num_str = str(num)  # Convert number to string to access digits easily
    for i in range(1, len(num_str)):
        if abs(int(num_str[i]) - int(num_str[i - 1])) != 1:
            return False
    return True

def find_good_numbers(N):
    """Find all 'good' numbers from 0 to N and print them."""
    result = [str(i) for i in range(N + 1) if is_good_number(i)]
    print(" ".join(result))

# Input Handling
N = int(input().strip())
find_good_numbers(N)