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
    TreeNode * lowestCommonAncestor(TreeNode* root, int p, int q){
         if(root==NULL)
            return NULL;
        if(root->val==p || root->val ==q)
            return root;
        TreeNode* lef=lowestCommonAncestor(root->left,p,q);
        TreeNode* rig=lowestCommonAncestor(root->right,p,q);
        if(lef!=NULL && rig!=NULL){
            return root;
        }
        if(lef!=NULL)
            return lef;
        return rig;
    }
    bool findpath(TreeNode* root, int startValue, string& src){
        if(root==NULL)
            return false;
        if(root->val==startValue)
            return true;
        
//         left
        src.push_back('L');
        if(findpath(root->left,startValue,src)){
            return true;
        }
        src.pop_back();
        
        src.push_back('R');
        if(findpath(root->right,startValue,src)){
            return true;
        }
        src.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* Lca=lowestCommonAncestor(root,startValue,destValue);
        
        string src="";
        string dest="";
        
        findpath(Lca,startValue,src);
        findpath(Lca,destValue,dest);
        string rest="";
        for(int i=0;i<src.length();i++){
            rest.push_back('U');
        }
        rest+=dest;
        return rest;
         
    }
};