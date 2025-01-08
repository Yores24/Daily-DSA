# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        a=[]
        m=[-1]

        def right(root,m,c):

            if root is None:
                return
            
            if m[0]<c:
                a.append(root.val)
                m[0]=c
            
            right(root.right,m,c+1)
            right(root.left,m,c+1)
        c=0
        right(root,m,c)
        return a