/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* BSTBuilder(vector<int> orderedEles, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(orderedEles[mid]);

        TreeNode* leftTree = BSTBuilder(orderedEles, left, mid - 1);
        TreeNode* rightTree = BSTBuilder(orderedEles, mid + 1, right);
        
        root->left = leftTree;
        root->right = rightTree;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        //get LL elements (increasing order)
        vector<int> LLelements;
        ListNode* aux = head;
        while(aux) {
            LLelements.push_back(aux->val);
            aux = aux->next;
        }

        TreeNode* newTree = BSTBuilder(LLelements, 0, LLelements.size() - 1);
        return newTree;
    }
};