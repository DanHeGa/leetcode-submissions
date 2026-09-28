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
    vector<int> inOrderElements;
    void inOrderTraversal(TreeNode* root) {
        if (!root) return;

        inOrderTraversal(root->left);
        inOrderElements.push_back(root->val);
        inOrderTraversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrderTraversal(root); //fill vector with elements in order
        //validate correct order, else, return false

        int n = inOrderElements.size();
        for (int i = 1; i < n; i++) {
            if (inOrderElements[i - 1] >= inOrderElements[i]) {
                return false;
            }
        }

        return true;
    }
};