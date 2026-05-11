def find_middle_earth(nums1, nums2):
    """
    Write your logic here.
    Parameters:
        nums1 (list): List of integers representing the first array
        nums2 (list): List of integers representing the second array
    Returns:
        float: The median of the two arrays
    """
    
    # Merge both arrays
    merged = nums1 + nums2
    
    # Sort the merged array
    merged.sort()
    
    total = len(merged)
    
    # If odd length, return middle element
    if total % 2 == 1:
        return float(merged[total // 2])
    
    # If even length, return average of two middle elements
    mid1 = merged[(total // 2) - 1]
    mid2 = merged[total // 2]
    
    return (mid1 + mid2) / 2.0


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()

    m = int(data[0])  # First value is m
    n = int(data[1])  # Second value is n
    nums1 = list(map(int, data[2:2 + m]))  # Next m values are nums1
    nums2 = list(map(int, data[2 + m:2 + m + n]))  # Next n values are nums2

    # Call user logic function and print the output
    result = find_middle_earth(nums1, nums2)
    print(f"{result:.1f}")


if __name__ == "__main__":
    main()