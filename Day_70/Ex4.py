class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for num in arr[1:]:
        current.next = ListNode(num)
        current = current.next
    return head

def segregate_linked_list(head, x):
    divisible_head = divisible_tail = ListNode()
    non_divisible_head = non_divisible_tail = ListNode()
    
    current = head
    while current:
        if current.val % x == 0:
            divisible_tail.next = current
            divisible_tail = divisible_tail.next
        else:
            non_divisible_tail.next = current
            non_divisible_tail = non_divisible_tail.next
        current = current.next
    
    divisible_tail.next = non_divisible_head.next
    non_divisible_tail.next = None
    
    return divisible_head.next

def print_linked_list(head):
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print(" ".join(result))

# Input processing
n = int(input().strip())
arr = list(map(int, input().split()))
x = int(input().strip())

head = create_linked_list(arr)
new_head = segregate_linked_list(head, x)
print_linked_list(new_head)