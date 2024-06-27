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
#include <vector>
#include <algorithm> // For std::find

class Solution {
public:
    void inorderTraversal(TreeNode* root, std::vector<int>& inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* buildBST(std::vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildBST(inorder, start, mid - 1);
        root->right = buildBST(inorder, mid + 1, end);

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        std::vector<int> inorder;
        inorderTraversal(root, inorder);

        auto it = std::find(inorder.begin(), inorder.end(), key);
        if (it != inorder.end()) {
            inorder.erase(it);
        }

        return buildBST(inorder, 0, inorder.size() - 1);
    }
};
