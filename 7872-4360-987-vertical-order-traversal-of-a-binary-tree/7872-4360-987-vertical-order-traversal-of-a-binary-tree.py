# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        mp=defaultdict(list)

        q=deque([(root,0,0)])

        while q:

            r,x,y=q.popleft()

            mp[x].append((y,r.val))

            if r.left:
                q.append((r.left,x-1,y+1))
            if r.right:
                q.append((r.right,x+1,y+1))
        
        a=[]
        for i in sorted(mp):

            column = sorted(mp[i], key=lambda p: (p[0], p[1]))
            # Extract node values for this column
            a.append([val for y, val in column])
        
        return a