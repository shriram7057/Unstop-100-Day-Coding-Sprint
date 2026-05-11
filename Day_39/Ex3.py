class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def multiply_linked_list_numbers(N, M):
    # Reverse the numbers as strings
    N_str = str(N)[::-1]
    M_str = str(M)[::-1]
    
    # Convert them back to integers and multiply
    result = int(N_str) * int(M_str)
    
    # Convert the result back to a string and reverse it
    result_str = str(result)[::-1]
    
    # Create the linked list from the reversed result string
    dummy_head = ListNode(0)
    current = dummy_head
    for char in result_str:
        current.next = ListNode(int(char))
        current = current.next
    
    return dummy_head.next

def print_linked_list(head):
    current = head
    result = []
    while current:
        result.append(str(current.val))
        current = current.next
    print(''.join(result[::-1]))  # Print in reverse order

# Reading input
N = int(input())
M = int(input())

# Multiplying the linked list numbers and getting the result in reverse order
result_head = multiply_linked_list_numbers(N, M)

# Printing the linked list
print_linked_list(result_head)