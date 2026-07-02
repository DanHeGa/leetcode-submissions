class Solution {
public:

    int find(int node, vector<int>& parents) {
        if (parents[node] != node) {
            parents[node] = find(parents[node], parents);
        }
        return parents[node];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1);
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
        }

        vector<int> res = {};
        vector<int> rank(n + 1, 0); 
        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            int root1 = find(node1, parents);
            int root2 = find(node2, parents);

            if (root1 == root2) {
                res = edge;
                continue;
            }

            if (rank[root1] < rank[root2]) {
                parents[root1] = root2;
            } else if (rank[root2] < rank[root1]) {
                parents[root2] = root1;
            } else {
                parents[root1] = root2;
                rank[root1]++;
            }
        }

        return res;
    }
};