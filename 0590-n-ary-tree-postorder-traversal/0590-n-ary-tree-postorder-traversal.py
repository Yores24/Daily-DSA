"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        a=[]
        def sol(root):
            if root is None:
                return
            for c in root.children:
                sol(c)
            a.append(root.val)
        
        sol(root)
        return a