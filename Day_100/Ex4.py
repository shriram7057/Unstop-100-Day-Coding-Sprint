# Function to rearrange the linked list
def rearrange_list(nums):
    # Initialize three groups
    group0, group1, group2 = [], [], []
    
    # Distribute elements into groups based on index modulo 3
    for i in range(len(nums)):
        if i % 3 == 0:
            group0.append(nums[i])
        elif i % 3 == 1:
            group1.append(nums[i])
        else:
            group2.append(nums[i])
    
    # Merge the groups back into the original list in-place
    index = 0
    for num in group0 + group1 + group2:
        nums[index] = num
        index += 1
    
    # Print the modified list
    print(" ".join(map(str, nums)))

# Read input
n = int(input())
nums = list(map(int, input().split()))

# Rearrange and print the list
rearrange_list(nums)