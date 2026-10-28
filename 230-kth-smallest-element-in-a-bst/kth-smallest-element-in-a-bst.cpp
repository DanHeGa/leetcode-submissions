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
    int res;
    void inOrder(TreeNode* root, int &currk, int k) {
        if (!root) {
            return;
        }

        inOrder(root->left, currk, k);
        currk++;
        if (currk == k) {
            res = root->val;
            return;
        }
        inOrder(root->right, currk, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        inOrder(root, count, k);
        return res;
    }
};