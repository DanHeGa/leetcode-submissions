class Solution {
public:

    int find(int node, unordered_map<int, int>& parents) {
        if (parents[node] == node) return node;
        return find(parents[node], parents);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> parents;
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
        }

        vector<int> res = {};
        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            int root1 = find(node1, parents);
            int root2 = find(node2, parents);

            if (root1 == root2) {
                res = edge;
                continue;
            }

            parents[root1] = root2;
        }

        return res;
    }
};