"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return root
        
        queue=[(root,0)]
        prev_nodel={}
        
        while(queue):
            node,level=queue.pop(0)
            
            if level in prev_nodel:
                prev_nodel[level].next=node
            if node.left:
                queue.append((node.left,level+1))
            if node.right:
                queue.append((node.right,level+1))
            
            prev_nodel[level]=node
            
        return root