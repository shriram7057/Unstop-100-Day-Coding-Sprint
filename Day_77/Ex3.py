import math
from functools import reduce

def is_bad_group(soldiers):
    # Compute the GCD of all elements
    overall_gcd = reduce(math.gcd, soldiers)
    
    # If GCD is 1, return True (bad group), else False
    return "true" if overall_gcd == 1 else "false"

# Reading input
N = int(input())  
soldiers = list(map(int, input().split()))

# Output the result
print(is_bad_group(soldiers))