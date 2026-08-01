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
    void inOrderTraversal(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }
        
        inOrderTraversal(root->left, ans);
        ans.push_back(root->val);
        inOrderTraversal(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrderTraversal(root, ans);
        return ans;
    }
};

/*
if null return 

Visit left child
visit tghe root
append curr node to result vector
visit right child

[1, 3, 2]

*/