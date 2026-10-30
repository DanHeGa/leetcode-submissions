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
    TreeNode* helper(int left, int right, int &preIdx, vector<int>& preorder, unordered_map<int, int> &inIdx) {
        if (left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;

        //get inorder idx
        int inIndex = inIdx[root->val];
        root->left = helper(left, inIndex - 1, preIdx, preorder, inIdx);
        root->right = helper(inIndex + 1, right, preIdx, preorder, inIdx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //save preorder indexes 
        unordered_map<int, int> inIdx;
        for (int i = 0; i < inorder.size(); i++) {
            inIdx[inorder[i]] = i;
        }

        int n = inorder.size();
        int pre = 0;
        return helper(0, n - 1, pre, preorder, inIdx);
    }
};