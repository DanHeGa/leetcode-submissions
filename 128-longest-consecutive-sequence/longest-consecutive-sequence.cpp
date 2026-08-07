struct UnionFind {
    unordered_map<int, int> parents;
    unordered_map<int, int> sizes;
    int maxSize = 1;

    UnionFind(vector<int> nums) {
        for (int num : nums) {
            parents[num] = num;
            sizes[num] = 1;
        }
    }

    int find(int node) {
        if (parents[node] != node) {
            parents[node] = find(parents[node]);
        }

        return parents[node];
    }

    void customUnion(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2) {
            return;
        }

        if (sizes[root1] < sizes[root2]) {
            parents[root1] = root2;
            sizes[root2] += sizes[root1];
            maxSize = max(maxSize, sizes[root2]);
        } else {
            parents[root2] = root1;
            sizes[root1] += sizes[root2];
            maxSize = max(maxSize, sizes[root1]);
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        UnionFind uf(nums);

        for (int num : nums) {
            if (uf.parents.contains(num + 1)) {
                uf.customUnion(num, num + 1);
            }
        }

        return uf.maxSize;
    }
};