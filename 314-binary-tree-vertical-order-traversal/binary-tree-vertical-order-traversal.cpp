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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        map<int, vector<int>> columns;

        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while(!q.empty()) {
            auto [weight, node] = q.front();
            q.pop();

            columns[weight].push_back(node->val);

            if (node->left) {
                q.push({weight - 1, node->left});
            } 
            if (node->right) {
                q.push({weight + 1, node->right});
            }
        }

        vector<vector<int>> ans;
        for (auto column : columns) {
            ans.push_back(column.second);
        }

        return ans;
    }
};

/*
DFS approach (O(nlogn) in time, O(n) in space)
inorder traversal 
use weight for each node (root 0, left -1, right +1)
in each visit, we append the element in the hashsmap with it's respective weight
we sort the hahmap based on the key (weight)
iterate over each elemnt in te hamap to push each value (group of nodess with same weight) into the result vector
return res

BFS approach (O(n) in time, O(n) in space)
start queue with pair {0, root}, 0 is the column
while queue not empty
get curr node into map based on weight (first elemnt in the nodePair)
pop curr node from queue
add pair {weight - 1, leftnode} to queue if left child not null
add pair {wight + 1, rightNode} to queue if right node not null
*/