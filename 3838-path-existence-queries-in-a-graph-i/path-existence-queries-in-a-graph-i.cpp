struct UnionFind {
    vector<int> parents;
    vector<int> rank;

    UnionFind(int n) {
        parents.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    //union by rank
    void union_(int a, int b) {
        //get root, if not the same, make them the same 
        int rootA = find(a);
        int rootB  = find(b);

        if (rootA == rootB) return;

        if (rank[rootA] < rank[rootB]) {
            parents[rootA] = rootB;
        } else if (rank[rootB] < rank[rootA]){
            parents[rootB] = rootA;
        } else {
            parents[rootB] = rootA;
            rank[rootA]++;
        }
    }

    bool sameGroup(int a, int b) {
        return find(a) == find(b);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n); // [0, 1, 2, 3]
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff){
                uf.union_(i, i - 1);
            }
        }

        int qSize = queries.size();
        vector<bool> res(qSize);
        for (int i = 0; i < qSize; i++) {
            vector<int> query = queries[i];
            res[i] = uf.sameGroup(query[0], query[1]);
        }

        return res;
    }
};