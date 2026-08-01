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
    map<int, vector<pair<int, int>>> columns;

    void print() {
        for (auto ele : columns) {
            cout << "weight: " << ele.first << " -> ";
            for (pair<int, int> nodePair : ele.second) {
                cout << "d: " << nodePair.first << " val: " << nodePair.second <<  ", ";
            }
            cout << endl;
        }
    }

    void verticalInOrder(TreeNode* root, int weight, int depth){
        if (!root) {
            return;
        }

        verticalInOrder(root->left, weight - 1, depth + 1);
        columns[weight].push_back({depth, root->val});
        verticalInOrder(root->right, weight + 1, depth + 1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        verticalInOrder(root, 0, 0);
        vector<vector<int>> res;

        print();

        for (auto weightGroup : columns) {
            vector<pair<int, int>> nodes = weightGroup.second;
            //sort by depth (because we already have them sorted by column order by using a map insstead of a unordered map)
            stable_sort(nodes.begin(), nodes.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });

            vector<int> subRes;
            for (pair<int, int> pairNode : nodes) {
                subRes.push_back(pairNode.second);
            }

            res.push_back(subRes);
        }

        return res;
    }
};

/*
inorder traversal 
use weight for each node (root 0, left -1, right +1)
in each visit, we append the element in the hashsmap with it's respective weight
we sort the hahmap based on the key (weight)
iterate over each elemnt in te hamap to push each value (group of nodess with same weight) into the result vector
return res
*/