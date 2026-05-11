from collections import deque

# Definition for a binary tree node
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Function to build a binary tree from level order input
def build_tree(level_order):
    if not level_order or level_order[0] == -1:
        return None

    root = TreeNode(level_order[0])
    queue = deque([root])
    index = 1

    while queue and index < len(level_order):
        node = queue.popleft()
        
        # Left child
        if index < len(level_order) and level_order[index] != -1:
            node.left = TreeNode(level_order[index])
            queue.append(node.left)
        index += 1
        
        # Right child
        if index < len(level_order) and level_order[index] != -1:
            node.right = TreeNode(level_order[index])
            queue.append(node.right)
        index += 1

    return root

# Function to check if two trees are identical with allowed swaps
def are_identical_with_swaps(root1, root2):
    # If both nodes are None, return True
    if not root1 and not root2:
        return True
    # If one node is None and the other is not, return False
    if not root1 or not root2:
        return False
    # If the values don't match, return False
    if root1.val != root2.val:
        return False

    # Check if trees are identical without swaps
    no_swap = (are_identical_with_swaps(root1.left, root2.left) and 
               are_identical_with_swaps(root1.right, root2.right))
    
    # Check if trees can be made identical by swapping left and right
    swap = (are_identical_with_swaps(root1.left, root2.right) and 
            are_identical_with_swaps(root1.right, root2.left))

    return no_swap or swap

# Input processing
tree1_input = list(map(int, input().split()))
tree2_input = list(map(int, input().split()))

# Build trees from level order input
tree1_root = build_tree(tree1_input)
tree2_root = build_tree(tree2_input)

# Check if trees can be made identical with swaps
print("true" if are_identical_with_swaps(tree1_root, tree2_root) else "false")