from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(level_order):
    if not level_order or level_order[0] == 'N':
        return None
    
    root = TreeNode(int(level_order[0]))
    queue = deque([root])
    i = 1
    
    while i < len(level_order):
        node = queue.popleft()
        
        if i < len(level_order) and level_order[i] != 'N':
            node.left = TreeNode(int(level_order[i]))
            queue.append(node.left)
        i += 1
        
        if i < len(level_order) and level_order[i] != 'N':
            node.right = TreeNode(int(level_order[i]))
            queue.append(node.right)
        i += 1
    
    return root

def find_parents(root):
    parent_map = {}
    queue = deque([root])
    
    while queue:
        node = queue.popleft()
        
        if node.left:
            parent_map[node.left.val] = node.val
            queue.append(node.left)
        
        if node.right:
            parent_map[node.right.val] = node.val
            queue.append(node.right)
    
    return parent_map

def find_LCA(parent_map, P, Q):
    ancestors = set()
    
    while P in parent_map:
        ancestors.add(P)
        P = parent_map[P]
    ancestors.add(P)  # Add root
    
    while Q not in ancestors:
        Q = parent_map[Q]
    
    return Q

if __name__ == "__main__":
    N = int(input())
    level_order = input().split()
    P, Q = map(int, input().split())
    
    root = build_tree(level_order)
    parent_map = find_parents(root)
    print(find_LCA(parent_map, P, Q))