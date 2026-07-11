class Solution {
public:

    int find(int x, vector<int> &parents) {
        if (parents[x] != x) {
            parents[x] = find(parents[x], parents);
        }

        return parents[x];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0); //generate individual component parents

        //update parents vector based on edges defined connections
        vector<int> rank(n, 0);
        for (auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            int root1 = find(node1, parents);
            int root2 = find(node2, parents);

            if (root1 == root2) continue;

            if (rank[root1] > rank[root2]) {
                parents[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parents[root1] = root2;
            } else { //both node's ranks are equal
                parents[root1] = root2;
                rank[root2]++;
            } 
        }

        int srcParent = find(source, parents);
        int dstParent = find(destination, parents);

        return srcParent == dstParent;

    }
};

/*
Prob
n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], 
source = 0, destination = 5

Sol:

parents = [0, 1, 2, 3, 4, 5]

after analyzing edges (with no path compression for more understandable example)
parents = [1, 1, 2, 3, 4, 5]
*/