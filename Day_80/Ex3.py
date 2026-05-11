def user_logic(n, arr):
    """
    Write your logic here.
    Parameters:
        n (int): Size of the array
        arr (list): List of integers representing elements of the array
    Returns:
        list: List of roll numbers that are never called out until the end in sequential order
    """
    called = set()
    
    # Iterate through each student
    for i in range(n):
        # If the current student's roll number (i+1) hasn't been called yet
        if (i + 1) not in called:
            # Call out the roll number specified by arr[i]
            called.add(arr[i])
    
    # Find all roll numbers that were never called out
    uncalled = [i + 1 for i in range(n) if (i + 1) not in called]
    
    return uncalled
    pass

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # First input is the integer n
    arr = list(map(int, data[1:]))  # Remaining input is the array of integers
    
    # Call user logic function and get the result
    result = user_logic(n, arr)
    
    # Print the output in the required format
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()