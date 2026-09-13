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
    int maxSum = INT_MIN;
    int maxSumHelper(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = maxSumHelper(root->left);
        int right = maxSumHelper(root->right);

        int sum = root->val + max(0, left) + max(0, right);
        if (sum > maxSum) {
            maxSum = sum;
        }

        return root->val + max(0, max(left, right));

    }
    int maxPathSum(TreeNode* root) {
        int sumHelperRes = maxSumHelper(root);
        return maxSum;
    }
};