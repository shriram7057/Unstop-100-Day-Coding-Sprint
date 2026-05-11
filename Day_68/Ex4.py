MOD = 10**9 + 7

def num_of_arrays(n, m, k):
    """
    Write your logic here.
    Parameters:
        n (int): Length of the array
        m (int): Maximum possible value of an element
        k (int): Target search cost
    Returns:
        int: Number of ways to build the array Arr under the mentioned conditions 
             (computed modulo 10^9 + 7)
    """
    pass

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # Length of the array
    m = int(data[1])  # Maximum possible value of an element
    k = int(data[2])  # Target search cost
    
    # Call user logic function and print the output
    result = num_of_arrays(n, m, k)
    print(result)

if __name__ == "__main__":
    main()