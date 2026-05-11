from bisect import bisect_left
import sys

def max_books_on_shelf(heights):
    """
    Finds the maximum number of books Luke can place on the new shelf in increasing order.
    
    Parameters:
        heights (list): List of integers representing the height of the books.
    
    Returns:
        int: Maximum number of books that can be placed on the new shelf.
    """
    if not heights:
        return 0

    # List to maintain the longest increasing subsequence
    lis = []

    for height in heights:
        pos = bisect_left(lis, height)  # Find the position to replace or append
        
        if pos == len(lis):  # If height is larger than all elements in LIS
            lis.append(height)
        else:  # Replace element at pos to maintain the smallest possible LIS
            lis[pos] = height

    return len(lis)

def main():
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # Number of books
    heights = list(map(int, data[1:]))  # Heights of books
    
    result = max_books_on_shelf(heights)
    print(result)

if __name__ == "__main__":
    main()