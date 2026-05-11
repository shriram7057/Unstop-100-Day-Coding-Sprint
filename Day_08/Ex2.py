def peakIndexInMountainArray(A):
    low, high = 0, len(A) - 1
    
    while low < high:
        mid = (low + high) // 2
        
        if A[mid] < A[mid + 1]:
            low = mid + 1
        else:
            high = mid
    
    return low

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(peakIndexInMountainArray(arr))