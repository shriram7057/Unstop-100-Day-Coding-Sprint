class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def create_linked_list(arr):
    """ Converts an array to a linked list and returns the head node. """
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for num in arr[1:]:
        current.next = ListNode(num)
        current = current.next
    return head

def mean_linked_list(head, K):
    """ Creates a Mean Linked List by computing mean for every K consecutive nodes. """
    if not head or K <= 0:
        return head

    # Convert linked list to array
    arr = []
    current = head
    while current:
        arr.append(current.val)
        current = current.next

    N = len(arr)

    # Special case: If K > N, return original linked list
    if K > N:
        return head

    # Compute means for every K group
    mean_list = []
    for i in range(0, N, K):
        chunk = arr[i:i+K]
        if len(chunk) == K:  # If full chunk, calculate mean
            mean_list.append(sum(chunk) // K)
        else:  # Remaining elements, append directly
            mean_list.extend(chunk)

    # Create the Mean Linked List
    return create_linked_list(mean_list)

def print_linked_list(head):
    """ Prints the linked list in the required format. """
    current = head
    while current:
        print(current.val, end=" --> ")
        current = current.next
    print("null")

# Read input
K = int(input().strip())
N = int(input().strip())
if N == 0:
    print("null")
else:
    arr = list(map(int, input().split()))
    head = create_linked_list(arr)
    mean_head = mean_linked_list(head, K)
    print_linked_list(mean_head)