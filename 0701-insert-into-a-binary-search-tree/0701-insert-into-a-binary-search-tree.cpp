/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int val){
        TreeNode* x;
        int f=0;
        while(root){
            if(root->val>val){
                x=root;
                f=0;
                root=root->left;
            }
            else{
                x=root;
                f=1;
                root=root->right;
            }
        }
        if(f){
            x->right=new TreeNode(val);
            
        }
        else{
            x->left=new TreeNode(val);
            
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        return new TreeNode(val);
        TreeNode* x=root;
        solve(x,val);
        
        return root;
    }
};