class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_sorted_lists(l1, l2):
    dummy = ListNode()
    current = dummy
    
    while l1 and l2:
        if l1.val <= l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next
    
    if l1:
        current.next = l1
    if l2:
        current.next = l2
    
    return dummy.next

def print_linked_list(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

def list_to_linked_list(arr):
    dummy = ListNode()
    current = dummy
    for num in arr:
        current.next = ListNode(num)
        current = current.next
    return dummy.next

# Input reading
n, m = map(int, input().split())
arr1 = list(map(int, input().split())) if n > 0 else []
arr2 = list(map(int, input().split())) if m > 0 else []

# Convert arrays to linked lists
l1 = list_to_linked_list(arr1)
l2 = list_to_linked_list(arr2)

# Merge the two sorted linked lists
merged_head = merge_sorted_lists(l1, l2)

# Print the merged list
print_linked_list(merged_head)