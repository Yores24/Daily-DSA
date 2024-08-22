# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        a=[]
        
        while head:
            a.append(head.val)
            head=head.next
        def build(a):
            if not a:
                return None
            
            mid=len(a)//2

            node=TreeNode(a[mid])

            node.left=build(a[:mid])
            node.right=build(a[mid+1:])

            return node
        return build(a)