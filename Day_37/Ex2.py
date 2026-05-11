class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" --> ")
            temp = temp.next
        print("null")

def process_linked_list(k, elements):
    n = len(elements)
    new_list = LinkedList()
    i = 0
    
    while i < n:
        if i + k <= n:  # If we have at least 'k' elements
            segment = elements[i:i + k]
            mean_val = sum(segment) // k  # Compute mean
            if mean_val % 2 == 0:  # Only add if mean is even
                new_list.append(mean_val)
            i += k
        else:  # If remaining elements are less than 'k'
            for j in range(i, n):
                new_list.append(elements[j])
            break
    
    new_list.display()

# Input reading
k = int(input().strip())
n = int(input().strip())
elements = list(map(int, input().split()))

# Processing
process_linked_list(k, elements)