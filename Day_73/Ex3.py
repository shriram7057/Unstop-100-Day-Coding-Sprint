def user_logic(n, s):
    """
    Write your logic here.
    Parameters:
        n (int): Length of the string s
        s (str): A string of length n consisting of lowercase letters only
    Returns:
        int: Number of distinct strings that can be formed by applying the rule of removing two consecutive letters
    """
    pass

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    T = int(data[0])  # Number of test cases
    index = 1
    results = []
    
    for _ in range(T):
        n = int(data[index])  # Length of the string
        s = data[index + 1]  # The string
        index += 2
        
        # Call user logic function and store the result
        result = user_logic(n, s)
        results.append(result)
    
    # Print all results for each test case
    for result in results:
        print(result)

if __name__ == "__main__":
    main()