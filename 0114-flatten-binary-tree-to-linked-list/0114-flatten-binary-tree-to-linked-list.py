class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:

        def preOrder(root):
            if root is None:
                return 
            # Root -- Left -- Right
            preorder_traversal_list.append(root.val)
            preOrder(root.left)
            preOrder(root.right)

        preorder_traversal_list = []
        preOrder(root) # Calling Pre-Order Traversal Func.
        print(preorder_traversal_list) # [1, 2, 3, 4, 5, 6]

        # As, We got the Traversal List,, Let's modify Given Binary Tree,, Such that For any of the Node in BT, Left Child will always be None,, and Right Child will be Val. in preorder_traversal_list

        # Let's use a Pointer to Traverse BT
        current = root # Initialized to Root

        for value in preorder_traversal_list[1:]: 
            # As, we Initialized Current with Root Node,, It has 1st value of List in it,, So, we have to Traverse the List from 2nd Element 

            current.left = None # Making the Left Child as None
            current.right = TreeNode(value) # Making the Right Child as a New TreeNode with corresponding Value

            current = current.right # Moving Current Node Pointer 

'''
--> If we Not Sliced the preorder_traversal_list
    --> for value in preorder_traversal_list: 
            # Given Ans. is [1,null,1,null,2,null,3,null,4,null,5,null,6]
    --> There (1,null) is repeated twice
'''